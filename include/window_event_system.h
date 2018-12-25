#ifndef ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_
#define ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_


#include <SFML/Graphics/RenderWindow.hpp>

#include <framework/active_system.h>
#include <framework/terminator_system.h>
#include <thread>
#include <mutex>
#include <imgui/imgui-SFML.h>

template <class T>
class ThreadSafeQueue {
  public:
    ThreadSafeQueue() = default;
    ~ThreadSafeQueue() = default;

    void enqueue(const T& data) {
        std::lock_guard<std::mutex> guard(mutex);
        queue.push(data);
    }
    const T& dequeue() {
        std::lock_guard<std::mutex> guard(mutex);
        const T& data = queue.front();
        queue.pop();
        return data;
    }
    bool is_empty() {
        return queue.empty();
    }

  private:
    std::queue<T> queue;
    std::mutex mutex;
};

void event_polling(const bool& terminator, sf::Window* window, ThreadSafeQueue<sf::Event>& queue) {
    sf::Event event{};
    while (terminator) {
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            if ((event.type != sf::Event::KeyPressed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) &&
                event.type != sf::Event::KeyReleased &&
                event.type != sf::Event::MouseMoved &&
                event.type != 4) {
                queue.enqueue(event);
            }
        }

        sf::sleep(sf::milliseconds(15));
    }
}

class WindowEventSystem : public ActiveSystem<NoneNode>, public TerminatorSystem {
  public:
    explicit WindowEventSystem(sf::RenderWindow* window):
            window(window) {
        thread = new std::thread(event_polling, std::ref(terminator), window, std::ref(queue));
    }

    ~WindowEventSystem() final {
        terminator = false;
        thread->join();
        delete thread;
    }

    void execute() override {
        sf::Event event{};
        while (!queue.is_empty()) {
            event = queue.dequeue();

            if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                //terminator = false;
                //thread->join();
                //delete thread;
                window->close();
            }

            if (event.type == sf::Event::Resized) {
                auto view = window->getView();
                sf::Vector2u size = window->getSize();
                view.setSize(size.x, size.y);
                window->setView(view);
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                static float scale_factor = 1;
                auto default_size = window->getSize();
                auto view = window->getView();
                auto delta = event.mouseWheelScroll.delta;
                if (delta > 0 && scale_factor < 2.0f) {
                    scale_factor += 0.5f * delta;

                } else if (delta < 0 && scale_factor > 0.5f){
                    scale_factor -= 0.5f * (-delta);
                }
                sf::Vector2f size = {default_size.x * scale_factor, default_size.y * scale_factor};
                view.setSize(size);
                window->setView(view);
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Middle) {
                    auto default_size = window->getSize();
                    auto view = window->getView();
                    view.setSize(sf::Vector2f(default_size));
                    window->setView(view);
                }
            }
        }
    }

  private:
    sf::RenderWindow* window;
    bool terminator = true;
    std::thread* thread = nullptr;
    ThreadSafeQueue<sf::Event> queue;
};

#endif  // ACID_INCLUDE_WINDOW_EVENT_SYSTEM_H_