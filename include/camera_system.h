#ifndef ACID_INCLUDE_CAMERA_SYSTEM_H_
#define ACID_INCLUDE_CAMERA_SYSTEM_H_

#include <algorithm>
#include <cstring>

#include <active_system.h>
#include <graphic_node.h>
#include <entity.h>

using graph_pair = std::pair<sf::Vector2f, GraphicNode*>;
using graph_vector = std::vector<graph_pair>;

class CameraSystem: public ISystem<GraphicNode> {
  public:
    void run() override {
        execute();
    }

    void execute() const override {

    }

    const graph_vector& get_scope(sf::Vector2f center, float width, float height) {
        visible_entity.clear();
        return x_sorted;
    }

    void on_update(GraphicNode* node) final {
        auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();

        for (auto &pair : x_sorted) {
            if (pair.second == node) {
                pair.first = vec;
                break;
            }
        }


    }

    void on_create(GraphicNode* node) final {
        auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();
        //std::cout << "\nx: "<< vec.x << " y: " << vec.y << std::endl;
        x_sorted.push_back(std::make_pair(vec, node));
    }

    void on_delete(GraphicNode* node) final {
        auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();

        auto pos = find_left(vec.x);
        // TODO check if there are several emtities on the same x
        x_sorted.erase(x_sorted.begin() + pos);
    }

  private:
    std::vector<GraphicNode*> visible_entity;
    graph_vector x_sorted;

    long find_left(float x) {
        auto& arr = x_sorted;
        size_t left_border = 0;
        size_t right_border = arr.size() - 1;

        if (x < x_sorted[left_border].first.x) {
            return -1;
        }

        if (x > x_sorted[right_border].first.x) {
            return right_border;
        }

        while (left_border + 1 < right_border) {
            size_t middle = (left_border + right_border) / 2;

            if (arr[middle].first.x > x) {
                right_border = middle;
            } else if (arr[middle].first.x < x){
                left_border = middle;
            } else {
                return middle;
            }
        }

        return arr[right_border].first.x == x ? right_border : left_border;
    }

    long find_right(float x) {
        auto& arr = x_sorted;
        size_t left_border = 0;
        size_t right_border = arr.size() - 1;

        if (x > x_sorted[right_border].first.x) {
            return -1;
        }

        if (x < x_sorted[left_border].first.x) {
            return left_border;
        }

        while (left_border + 1 < right_border) {
            size_t middle = (left_border + right_border) / 2;

            if (arr[middle].first.x > x) {
                right_border = middle;
            } else if (arr[middle].first.x < x){
                left_border = middle;
            } else {
                return middle;
            }
        }

        return arr[left_border].first.x == x ? left_border : right_border;
    }

};


#endif  // ACID_INCLUDE_CAMERA_SYSTEM_H_
