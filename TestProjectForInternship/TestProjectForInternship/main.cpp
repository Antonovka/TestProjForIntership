#include <iostream>
#include <assert.h>

#include "Game.h"

using namespace std;

bool TestCreatePlayer();
bool TestWrongDefense();
bool TestWrongAttack();
bool TestWrongHealth();
bool TestPlayerTakeDamage();
bool TestPlayerHeal();
bool TestPlayerIsDead();
bool TestPlayerHealAfterDeath();

int main() {
	std::cout << "Start testing" << std::endl;

	assert(TestCreatePlayer());
	assert(TestWrongDefense());
	assert(TestWrongAttack());
	assert(TestWrongHealth());
	assert(TestPlayerTakeDamage());
	assert(TestPlayerHeal());
	assert(TestPlayerIsDead());
	assert(TestPlayerHealAfterDeath());

	return 0;
}

bool TestCreatePlayer() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 10;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	if (player.GetName().compare(name) != 0) {
		return false;
	}

	if (player.GetDefense() != defense) {
		return false;
	}

	if (player.GetAttack() != attack) {
		return false;
	}

	if (player.GetHealth() != health) {
		return false;
	}

	return true;
}

bool TestWrongDefense() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 50;
	int health = 10;
	Game::DamageRange damageRange(0, 10);

	try {
		Game::Player player(name, attack, defense, health, damageRange);
		return false;
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	return true;
}

bool TestWrongAttack() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 50;
	int defense = 10;
	int health = 10;
	Game::DamageRange damageRange(0, 10);

	try {
		Game::Player player(name, attack, defense, health, damageRange);
		return false;
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	return true;
}

bool TestWrongHealth() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 50;
	int defense = 10;
	int health = 10;
	Game::DamageRange damageRange(0, 10);

	try {
		Game::Player player(name, attack, defense, health, damageRange);
		return false;
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	return true;
}

bool TestPlayerTakeDamage() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 100;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	int damage = 10; 
	player.TakeDamage(damage);

	if (player.GetHealth() != (health - damage)) {
		return false;
	}

	return true;
}

bool TestPlayerHeal() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 100;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	int damage = 50;
	player.TakeDamage(damage);

	player.Heal();

	if (player.GetHealth() <= health - damage) {
		return false;
	}

	if (player.GetHealth() >= health) {
		return false;
	}

	return true;
}

bool TestPlayerIsDead() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 100;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	int damage = health + 50;
	player.TakeDamage(damage);

	if (!player.IsDead()) {
		return false;
	}

	return true;
}

bool TestPlayerHealAfterDeath() {
	std::cout << __func__ << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 100;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	int damage = health + 50;
	player.TakeDamage(damage);

	player.Heal();

	if (!player.IsDead()) {
		return false;
	}

	if (player.GetHealth() != 0) {
		return false;
	}

	return true;
}
