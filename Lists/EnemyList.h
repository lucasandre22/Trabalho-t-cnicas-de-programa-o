#pragma once
#include "../Entities/Enemy.h"
#include <vector>
#include <fstream>
class Enemy;
class EnemyList
{
private:
    std::vector<Enemy*> vector;
public:
    EnemyList(){}
	~EnemyList(){}
    void Include(Enemy* elem){ vector.push_back(elem); }
	void Remove(Enemy* elem) { vector.erase(std::find(vector.begin(), vector.end(), elem)); delete elem; }
	void RemoveAll() { for (unsigned int i = 0; i < vector.size(); i++) { delete vector.at(i); } }
	void Clear() { vector.clear(); }
	const size_t getSize() { return vector.size(); }
	Enemy* operator[](int i);
};

