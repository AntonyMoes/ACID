#ifndef ACID_INCLUDE_FRAMEWORK_TYPE_ID_MANAGER_H_
#define ACID_INCLUDE_FRAMEWORK_TYPE_ID_MANAGER_H_


#include <cstdint>
#include "i_singleton.h"

template <class T>
class TypeIdManager : public ISingleton<TypeIdManager<T>> {
  public:
    void set_type_id(uint16_t _type_id) {
        type_id = _type_id;
    }

    uint16_t dispence_id() {
        static uint16_t id = 1;
        return id++;
    }

    void notify_id_deleted(uint16_t id) {
        // For future more accurate id management
    }

  private:
    uint16_t type_id;
};

#endif  // ACID_INCLUDE_FRAMEWORK_TYPE_ID_MANAGER_H_
