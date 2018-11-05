#ifndef ACID_INCLUDE_COMPONENT_MANAGER_H_
#define ACID_INCLUDE_COMPONENT_MANAGER_H_

#include <vector>
#include <i_component.h>

class ComponentManager {
  public:
	ComponentManager();
	~ComponentManager();
	IComponent* add_component(size_t type);       // Создает компонент по типу
	void delete_component(IComponent* component); // Удаляет компонент
	
  private:
	std::vector<IComponent*> components;
}; 

#endif