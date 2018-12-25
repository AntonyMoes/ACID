#ifndef ACID_INCLUDE_NAME_COMPONENT_H_
#define ACID_INCLUDE_NAME_COMPONENT_H_

#include <i_component.h>


class NameComponent: public IComponent {
  public:
    explicit NameComponent(bool _is_player) : player(_is_player) {}

    void set_network_id(uint16_t id) {
        this->id = id;
    }

    uint16_t get_network_id() {
        return id;
    }
    bool is_player() { return player; }
  private:
    uint16_t id = 0;
    std::string name;
    bool player;
};

#endif  // ACID_INCLUDE_NAME_COMPONENT_H_
