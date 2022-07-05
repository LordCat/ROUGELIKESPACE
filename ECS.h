#pragma once
/* This is my BASIC implementation of a Entity-Component-System manager,
* To whatever doomed soul that looks at this. I currently have 0% knowlage of how this memory stack works or whatever
* but Hell I'm going to give it a ago.
* 
* Some sources that I pulled for starting this are the first result on google when you type "ECS C++"
* as well as Lets Make Games on Youtube. 
* This is going to evolve over the years
* 
* -LordCat July 5th 2022
*/
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

//define classes 
//I'm using them both in the same file but this should probally be seperated
//into two. Please bear with me for now.

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID();
}

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};

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
	//A entity needs to be destoryed in order of active to be set to false 
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

		componentArray[getComponentTypeID<T>()] = c;
		ComponentBitset[getComponentTypeID<T>()] = true;

		c->init();
		return *c;
	}

	template<typename T> T& getComponent() const
	{
		auto ptr(componentArray[getComponentTypeID<T>()]);
		reutnr* static_cast<T*>(ptr);
	}
	
class Manager
	{
	private:
		std::vector<std::unique_ptr<Entity>> entities;

	public:
		void update()
		{
			for (auto& e : entities) e->update();
		}

		void draw()
		{
			for (auto& e : entities) e->draw();
		}

		void refresh()
		{
			entities.erase(std::remove_if(std::begin(entities), std::end(entities), [](const std::unique_ptr<Entity>& mEntity)
				{return !mEntity->isActive(); }),
				std::end(entities));
		}

		Entity& addEntity()
		{
			Entity* e = new Entity();
			std::unique_ptr<Entity> uPtr{ e };
			entities.emplace_back(std::move(uPtr));
			return *e;
		}
};
}