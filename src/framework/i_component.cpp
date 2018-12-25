#include <i_component.h>
#include <framework/i_component.h>


uint16_t IComponent::get_parent_id() {
	return parent_id;
}
void IComponent::set_parent_id(uint16_t _parent_id) {
	parent_id = _parent_id;
}

void IComponent::update(){
	for (auto observer: observers) {
		observer->on_update(this);
	}
}

IComponent::~IComponent() {
    for (auto &observer : observers) {
        delete_observer(observer);
    }
}

