#include "CollisionManager.h"
#include <iostream>
CollisionManager* CollisionManager::instance = 0;
CollisionManager::CollisionManager(){
	this->entList = EntityList::getInstance();
	this->deltaX = 0.0f;
	this->deltaY = 0.0f;
	this->intersectX = 0.0f;
	this->intersectY = 0.0f;
}

CollisionManager* CollisionManager::getInstance(){
	if (instance == 0) {
		instance = new CollisionManager;
	}
	return instance;
}

CollisionManager::~CollisionManager(){}

bool CollisionManager::Colliding(Entity* e1, Entity* e2){
	this->deltaX = e1->getPositionX() - e2->getPositionX();
	this->deltaY = e1->getPositionY() - e2->getPositionY();
	this->intersectX = abs(this->deltaX) - (e1->getHalfSizeX() + e2->getHalfSizeX());
	this->intersectY = abs(this->deltaY) - (e1->getHalfSizeY() + e2->getHalfSizeY());
	return (this->intersectX < 0.0f && this->intersectY < 0.0f);
}

void CollisionManager::Collided() {
	for (unsigned int i = 0; i < pairvector.size(); ++i) {
		if (pairvector.at(i)->getType() == "Boss" || pairvector.at(i)->getType() == "Player1" ||
			pairvector.at(i)->getType() == "Wizard" || pairvector.at(i)->getType() == "Spikewall" ||
			pairvector.at(i)->getType() == "Bat" || pairvector.at(i)->getType() == "Player2") { //� verificado a colis�o apenas dessas entidades com as outras
			for (unsigned int j = 0; j < pairvector.size(); ++j) {
				if (Colliding(pairvector.at(i), pairvector.at(j)) && i != j) {
					if (pairvector.at(i)->getType() == "Player2" && pairvector.at(j)->getType() == "Projectile" && 
						!static_cast<Projectile*>(pairvector.at(j))->getfromPlayer()) { //colis�o player2 com projetil inimigo
						static_cast<Player2*>(pairvector.at(i))->damageToPlayer1();
						this->entList->Remove(pairvector.at(j));
						this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(j)));
					}
					else if (pairvector.at(i)->getType() == "Player1") { //entra no if para verificar colis�o com players
						if (pairvector.at(j)->getType() == "Platform") { //colis�o player com plataforma
							if (this->intersectX > this->intersectY) {
								if (this->deltaX > 0.0f) { this->pairvector.at(i)->Move(-this->intersectX, 0.0f); }
								else { this->pairvector.at(i)->Move(this->intersectX, 0.0f); }
							}
							else {
								if (this->deltaY > 0.0f) { this->pairvector.at(i)->Move(0.0f, -this->intersectY); }
								else {
									this->pairvector.at(i)->Move(0.0f, this->intersectY);
									static_cast<Player1*>(this->pairvector.at(i))->setVelocityY(0.0f);
									static_cast<Player1*>(this->pairvector.at(i))->setJumping(true);
								}
							}
						}
						else if (pairvector.at(j)->getType() == "Portal") { //colis�o player com portal
							static_cast<Portal*>(pairvector.at(j))->Teleport();
						}
						else if (pairvector.at(j)->getType() == "Wizard" || pairvector.at(j)->getType() == "Bat" ||
							pairvector.at(j)->getType() == "Boss" || pairvector.at(j)->getType() == "Spikeball") { //colis�o player com inimigos e os outros obst�culos, portal e projetil j� verificados
							static_cast<Player1*>(pairvector.at(i))->setTakingDamage(true);
						}
						else if (pairvector.at(j)->getType() == "Projectile" && //colis�o player1 com proj�til inimigo
							!static_cast<Projectile*>(pairvector.at(j))->getfromPlayer()) {
							static_cast<Player1*>(pairvector.at(i))->setTakingDamage(true);
							this->entList->Remove(pairvector.at(j));
							this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(j)));
						}
					}
					else if (pairvector.at(i)->getType() == "Spikewall" && pairvector.at(j)->getType() == "Projectile" &&
						static_cast<Projectile*>(pairvector.at(j))->getfromPlayer()) { //colis�o proj�til do player com obst�culo spikewall
						this->entList->Remove(pairvector.at(i));
						this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(i)));
						this->entList->Remove(pairvector.at(j - 1));
						this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(j - 1)));
					}
					else if (pairvector.at(j)->getType() == "Projectile" &&
						static_cast<Projectile*>(pairvector.at(j))->getfromPlayer()) { //colis�o inimigo e projetil do player
						static_cast<Enemy*>(pairvector.at(i))->setTakingDamage(true);
						this->entList->Remove(pairvector.at(j));
						this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(j)));
					}
				}
			}
		}
		if (pairvector.at(i)->getType() == "Wizard" || pairvector.at(i)->getType() == "Boss" || 
			pairvector.at(i)->getType() == "Bat"){ //exclui inimigos, pois existe anima��o antes de ser deletado
			if (!static_cast<Enemy*>(pairvector.at(i))->getAlive()){
				this->entList->Remove(pairvector.at(i));
				this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(i)));
			}
		}
		else if (pairvector.at(i)->getType() == "Projectile" &&
				static_cast<Projectile*>(this->pairvector.at(i))->getRangeCount() >
				static_cast<Projectile*>(this->pairvector.at(i))->getRange()) { //exclui proj�til out of range
				this->entList->Remove(pairvector.at(i));
				this->pairvector.erase(std::find(pairvector.begin(), pairvector.end(), pairvector.at(i)));
		}
	}
}

void CollisionManager::Clear(){
	if (this->pairvector.size() != 0) {
		for (auto& i : pairvector) {
			this->entList->Remove(static_cast<Entity*>(i));
			this->pairvector.clear();
		}
	}
}


