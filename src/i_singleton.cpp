#include <i_singleton.h>

ISingleton& ISingleton::get_instance() {
    static ISingleton instance;
    return instance;
}
