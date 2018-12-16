#ifndef ACID_INCLUDE_EXP_COMPONENT_H_
#define ACID_INCLUDE_EXP_COMPONENT_H_


#include <i_component.h>

class ExpComponent: public IComponent {
  public:
    ExpComponent(size_t exp_before_up, size_t exp_for_death,
                float lvlup_coef, float death_exp_coef):
            exp_before_up(exp_before_up),
            exp_for_death(exp_for_death),
            lvlup_coef(lvlup_coef),
            death_exp_coef(death_exp_coef) {}

    size_t get_level() const {
        return lvl;
    }

    size_t get_death_exp() const {
        return exp_for_death;
    }

    void up_level(size_t lvl_count) {
        lvl += lvl_count;
        exp_for_death *= death_exp_coef;
        update();
    }

    void add_exp(size_t exp) {
        tmp_exp += exp;
        while (tmp_exp >= exp_before_up) {
            tmp_exp -= exp_before_up;
            up_level(1);
            exp_before_up *= lvlup_coef;
        }
    }

  private:
    size_t lvl = 0;
    size_t tmp_exp = 0;
    size_t exp_before_up;
    size_t exp_for_death;

    float lvlup_coef;
    float death_exp_coef;
};

#endif   // ACID_INCLUDE_EXP_COMPONENT_H_
