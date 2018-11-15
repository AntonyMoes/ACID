#ifndef ACID_INCLUDE_INPUT_COMPONENT_H_
#define ACID_INCLUDE_INPUT_COMPONENT_H_


#include <array>

#include <framework/i_component.h>

class InputComponent : public IComponent {
  public:
    const std::array<bool, 101>& get_keys() {
        return keys;
    }

    size_t get_keys_count() {
        return keys_count;
    }

    void set_keys_and_count(const std::array<bool, 101>& keys, size_t count) {
        this->keys = keys;
        this->keys_count = count;
        update();
    }

  private:
    std::array<bool, 101> keys = {};
    size_t keys_count = 0;
};

#endif  // ACID_INCLUDE_INPUT_COMPONENT_H_
