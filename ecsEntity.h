#pragma once


#include "ecsManager.h"
#include "ecsComponent.h"

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

class Entity
{

private:
	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArray;

	ComponentBitset componentBitSet;

public:
	void update()
	{
		for (auto& c : components) c->update();
		for (auto& c : components) c->draw();
	}
	void draw() {}
	//check if the component is active or not
	bool isActive() const { return active; }
	//A entity needs to be destoryed in order for active flag to be set to false 
	void destory() { active = false; }
	//Check if an entity has a component
	template<typename T> bool hasComponent() const
	{
		return ComponentBitset[getComponentID<T>];
	}

	template<typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(std::forward<TArgs>(mArgs)...));
		c->entity = this;
		std::unique_ptr<Component> uPtr{ c };
		components.emplace_back(std::move(uPtr));
		//Getting out componentArray to set the components to C

		ComponentArray[getComponentTypeID] = c;
		ComponentBitset[getComponentTypeID ] = true;

		c->init();
		return *c;
	}

	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		return*static_cast<T*>(ptr);
	}
};