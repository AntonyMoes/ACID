#ifndef ACID_INCLUDE_CAMERA_SYSTEM_H_
#define ACID_INCLUDE_CAMERA_SYSTEM_H_

#include <algorithm>
#include <cstring>

#include <active_system.h>
#include <graphic_node.h>
#include <entity.h>

using graph_pair = std::pair<sf::Vector2f, TextureComponent*>;
using graph_vector = std::vector<graph_pair>;

class CameraSystem: public ISystem<GraphicalNode> {
  public:
    void execute() const override {

    }

    graph_vector& get_scope(sf::Vector2f center, float width, float height) {
        visible_entity.clear();

        width += 100;
        height += 100;
        auto left_border = center.x - width / 2;
        auto right_border = center.x + width / 2;
        auto bottom_border = center.x + height / 2;
        auto top_border = center.x - height / 2;

        std::sort(x_sorted.begin(), x_sorted.end(), [](graph_pair first, graph_pair second) { return first.first.x < second.first.x; });

        auto left = find_right(left_border);
        if (left == -1) {
            return visible_entity;
        }

        auto right = find_left(right_border);

        for (auto i = left; i <= right; ++i) {
            if (x_sorted[i].first.x > top_border && x_sorted[i].first.x < bottom_border) {
                visible_entity.push_back(x_sorted[i]);
            }
        }

        return visible_entity;
    }

    void on_update(GraphicalNode* node) final {
        // sort();
    }

    void on_create(GraphicalNode* node) final {
        /*auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();
        auto *texture_comp = node->get_component<TextureComponent>();
        x_sorted.emplace_back();
        auto temp = std::make_pair(vec, texture_comp);

        auto pos = find_left(vec.x);
        // TODO shift everething write by 1 position
        x_sorted[pos] = temp;*/

        auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();
        auto *texture_comp = node->get_component<TextureComponent>();
        x_sorted.push_back(std::make_pair(vec, texture_comp));
    }

    void on_delete(GraphicalNode* node) final {
        auto *pos_comp = node->get_component<PositionComponent>();
        auto vec = pos_comp->get_coords();

        auto pos = find_left(vec.x);
        // TODO check if there are several emtities on the same x
        x_sorted.erase(x_sorted.begin() + pos);

        //std::memmove(&x_sorted[pos], &x_sorted[pos + 1], x_sorted.size() - 1 - pos);  // TODO -> make cycle
        //x_sorted.pop_back();
    }

  private:
    graph_vector visible_entity;
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
