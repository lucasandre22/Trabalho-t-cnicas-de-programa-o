#pragma once
#include "../Entities/Platform.h"
#include <vector>
class Platform;
class PlatformList
{
private:
    std::vector<Platform*> vector;
public:
    PlatformList(){}
	~PlatformList(){}
    void Include(Platform* elem){ vector.push_back(elem); }
    void Remove(Platform* elem){ vector.erase(std::find(vector.begin(), vector.end(), elem)); }
	void RemoveAll(){ for (unsigned int i = 0; i < vector.size(); i++) { delete vector.at(i); } }
    Platform* operator[](int i);
	void Clear() { vector.clear(); }
	const size_t getSize() { return vector.size(); }
};



