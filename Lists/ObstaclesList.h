#pragma once
#include <vector>
#include <fstream>
#include "../Entities/Obstacle.h"
class Obstacle;
class ObstacleList
{
private:
	std::vector<Obstacle*> vector;

public:
	ObstacleList(){}
	~ObstacleList() {}
	void Include(Obstacle* elem) { vector.push_back(elem); }
	void Remove(Obstacle* elem) { vector.erase(std::find(vector.begin(), vector.end(), elem)); delete elem; }
	void RemoveAll(){ for (unsigned int i = 0; i < vector.size(); i++) { delete vector.at(i); } }
	void Clear() { vector.clear(); }
	const size_t getSize() { return vector.size(); }
	Obstacle* getObstacles(int i) { return vector.at(i); }
};

