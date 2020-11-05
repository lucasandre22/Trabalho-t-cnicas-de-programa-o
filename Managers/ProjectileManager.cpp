#include "ProjectileManager.h"

ProjectileManager::ProjectileManager()
{
	this->window = GraphicManager::getInstance();
	this->player1 = nullptr;
	this->player2 = nullptr;
	this->eneList = nullptr;
	this->entList = nullptr;
	this->projList = nullptr;
	this->cooldownCountPlayer1 = 0.0f;
	this->cooldownCountPlayer2 = 0.0f;
}

ProjectileManager::~ProjectileManager()
{

}

void ProjectileManager::AddProjectile(Projectile* p){
	projList->Include(p);
	entList->Add(static_cast<Entity*>(p));
}

void ProjectileManager::RemoveProjectile(Projectile* p){
	entList->Remove(static_cast<Entity*>(p));
	projList->Remove(p);
}

void ProjectileManager::Player1Shooting(){
	if (player1->Shooting() && player1->getAlive() && !player1->getAttacking()) {
		AddProjectile(player1->CreateProjectile());
		player1->setAttacking(true);
	}
}

void ProjectileManager::Player1Cooldown(){
	cooldownCountPlayer1 += window->getDeltaTime();
	if (cooldownCountPlayer1 > this->player1->getCooldown()) {
		cooldownCountPlayer1 = 0.0f;
		player1->setAttacking(false);
	}
}

void ProjectileManager::Player2Shooting(){
	if (player2->Shooting() && player2->getAlive() && !player2->getAttacking()) {
		AddProjectile(player2->CreateProjectile());
		player2->setAttacking(true);
	}
}

void ProjectileManager::Player2Cooldown(){
	cooldownCountPlayer2 += window->getDeltaTime();
	if (cooldownCountPlayer2 > this->player2->getCooldown()) {
		cooldownCountPlayer2 = 0.0f;
		player2->setAttacking(false);
	}
}

void ProjectileManager::EnemyShooting(){
	for (auto i = 0; i < eneList->getSize(); i++) {
		if ((*eneList)[i]->getEnemyShoots() && (*eneList)[i]->getAlive() && !(*eneList)[i]->getAttacking()){
			if (abs((player1->getPositionX() - (*eneList)[i]->getPositionX())) < (*eneList)[i]->getSightRangeX() &&
				abs((player1->getPositionY() - (*eneList)[i]->getPositionY())) < (*eneList)[i]->getSightRangeY() ||
				abs((player2->getPositionX() - (*eneList)[i]->getPositionX())) < (*eneList)[i]->getSightRangeX() &&
				abs((player2->getPositionY() - (*eneList)[i]->getPositionY())) < (*eneList)[i]->getSightRangeY()){
				enemyFaceRight((*eneList)[i]);
				(*eneList)[i]->setAttacking(true);
				AddProjectile((*eneList)[i]->CreateProjectile());
			}
		}
	}
}

void ProjectileManager::enemyFaceRight(Enemy* e){
	if (player1->getPositionX() - e->getPositionX() < 0) {
		e->setFaceRight(false);
	}
	else{
		e->setFaceRight(true);
	}
}

void ProjectileManager::outOfRangeCheck(){
	for (auto i = 0; i < projList->getSize(); i++){
		if (projList->getProjectile(i)->OutofRange()) {
			RemoveProjectile(projList->getProjectile(i));
		}
	}
}

void ProjectileManager::manageProjectiles(){
	Player1Shooting();
	Player1Cooldown();
	Player2Shooting();
	Player2Cooldown();
	EnemyShooting();
	outOfRangeCheck();
}

