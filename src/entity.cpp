#include <entity.h>
#include <typeindex>

template<class C>
void Entity::add_component() {
    components[std::type_index(typeid(C)).hash_code()] = C();
}