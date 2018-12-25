#ifndef ACID_INCLUDE_EXP_COMPONENT_H_
#define ACID_INCLUDE_EXP_COMPONENT_H_


#include <i_component.h>

class ExpComponent: public IComponent {
  public:
    ExpComponent(uint16_t exp_before_up, uint16_t exp_for_death,
                float lvlup_coef, float death_exp_coef):
            exp_before_up(exp_before_up),
            exp_for_death(exp_for_death),
            lvlup_coef(lvlup_coef),
            death_exp_coef(death_exp_coef) {}

    uint16_t get_level() const {
        return lvl;
    }

    uint16_t get_tmp_exp() const {
        return tmp_exp;
    }

    uint16_t get_exp_before_up() const {
        return exp_before_up;
    }

    uint16_t get_exp_for_death() const {
        return exp_for_death;
    }

    float get_lvlup_coef() const {
        return lvlup_coef;
    }

    float get_death_exp_coef() const {
        return death_exp_coef;
    }

    void set_level(uint16_t level) {
        lvl = level;
        if (level > lvl) {
            update();
        }
    }

    void set_tmp_exp(uint16_t exp) {
        tmp_exp = exp;
    }

    void set_exp_before_up(uint16_t exp) {
        exp_before_up = exp;
    }

    void set_exp_for_death(uint16_t exp) {
        exp_for_death = exp;
    }

    void set_lvlup_coef(float coef) {
        lvlup_coef = coef;
    }

    void set_death_exp_coef(float coef) {
        death_exp_coef = coef;
    }

    void add_exp(uint16_t exp) {
        tmp_exp += exp;
        while (tmp_exp >= exp_before_up) {
            tmp_exp -= exp_before_up;
            up_level(1);
            exp_before_up *= lvlup_coef;
        }
        update();
    }

  private:
    void up_level(uint16_t lvl_count) {
        lvl += lvl_count;
        exp_for_death *= death_exp_coef;
    }
    
    uint16_t lvl = 0;
    uint16_t tmp_exp = 0;
    uint16_t exp_before_up;
    uint16_t exp_for_death;

    float lvlup_coef;
    float death_exp_coef;
};

#endif   // ACID_INCLUDE_EXP_COMPONENT_H_
