#pragma once
#include "../Entities/Projectile.h"
#include <vector>
class Projectile;
class ProjectileList
{
private:
	std::vector<Projectile*> vector;
public:
	ProjectileList();
	~ProjectileList() {}
	void Include(Projectile* elem) { vector.push_back(elem); }
	void Remove(Projectile* elem) { cout << "entrou remove projlist" << endl; vector.erase(find(vector.begin(), vector.end(), elem)); }
	Projectile* getProjectile(int i) { return vector.at(i); }
	void Clear() { vector.clear(); }
	const size_t getSize() { return vector.size(); }
	bool empty() { return vector.empty(); }
};


