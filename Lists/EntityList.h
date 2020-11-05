#pragma once
#include "../Lists/TemplateList.h"
#include "../Entities/Entity.h"
using namespace np_TemplateList;
class Entity;
class EntityList
{
private:
    np_TemplateList::TemplateList<Entity*> list;
	np_TemplateList::TemplateList<Entity*>::Iterator ptr;
	static EntityList* instance;
	EntityList() { }
public:
	static EntityList* getInstance();
	~EntityList() {}
	void Add(Entity* elem) { list.include(elem); }
	void Size() {
		int i = 0;
		for (ptr = list.begin(); ptr != list.end() && list.begin() != nullptr; ptr++){
			i++;
		}
		cout << i;
	}
	void Update() { for (ptr = list.begin(); ptr != list.end() && list.begin() != nullptr; ptr++) { (*ptr)->Update(); } }
	void Draw() { for (ptr = list.begin(); ptr != list.end() && list.begin() != nullptr; ptr++) { (*ptr)->Draw(); } }
	void Remove(Entity* elem) { list.Remove(elem); }
	void Clear() { list.clear(); }
};

