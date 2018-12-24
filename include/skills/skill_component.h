#ifndef A_C_I_D_SKILL_COMPONENT_H
#define A_C_I_D_SKILL_COMPONENT_H


#include <framework/i_component.h>
#include <cassert>

class SkillComponent : public IComponent {
  public:

    enum skill{hp = 1, mana = 2, burst = 3};

    void add_skill_point() {
        max_skill_points++;
        skill_points++;
        //update();
    }

    void dispence_skill_point(uint16_t points = 1) {
        assert(skill_points - points >= 0);
        skill_points -= points;
        //update();
    }

    uint16_t get_skill_points() const {
        return skill_points;
    }

    uint16_t get_max_skill_points() const {
        return max_skill_points;
    }

    void lvl_up_burst () {
        assert(burst_lvl < burst_max_lvl);
        dispence_skill_point();
        burst_lvl++;
        //update();
    }

    uint16_t get_burst_lvl() const {
        return burst_lvl;
    }

    uint16_t get_burst_max_lvl() const {
        return burst_max_lvl;
    }

    void set_skill_updated(skill s) {
        skill_updated = s;
        update();
    }

    uint16_t get_skill_updated() {
        return skill_updated;
    }


  private:
    uint16_t skill_points = 0;
    uint16_t max_skill_points = 0;
    uint16_t burst_lvl = 0;
    uint16_t burst_max_lvl = 4;
    uint16_t skill_updated = 0;
};

#endif //A_C_I_D_SKILL_COMPONENT_H
