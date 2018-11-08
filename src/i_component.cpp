#include <i_component.h>

size_t IComponent::get_parent_id() {
	return parent_id;
}
void IComponent::set_parent_id(size_t _parent_id) {
	parent_id = _parent_id;
}