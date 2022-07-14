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
//#include "ecsManager.h"
#include "ecsManager.h"
#include "ecsEntity.h"


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
	return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
	Entity* Entity;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};