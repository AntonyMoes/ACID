#ifndef ACID_INCLUDE_COMPONENT_MANAGER_H_
#define ACID_INCLUDE_COMPONENT_MANAGER_H_


#include <vector>
#include <cstdlib>

#include <i_component.h>
#include <i_observer.h>

class ComponentManager : IObserver<IComponent> {
  public:
	ComponentManager();
	~ComponentManager();
	IComponent* add_component(size_t type);       // Создает компонент по типу
	void delete_component(IComponent* component); // Удаляет компонент
	void on_delete(IComponent* sender);
  private:
	std::vector<IComponent*> components;
}; 

#endif  // ACID_INCLUDE_COMPONENT_MANAGER_H_