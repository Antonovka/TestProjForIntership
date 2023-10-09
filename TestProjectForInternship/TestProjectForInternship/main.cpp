#include <iostream>
#include <assert.h>

#include "Game.h"

using namespace std;

bool TestCreatePlayer();
bool TestWrongDefense();
bool TestWrongAttack();

int main() {
	std::cout << "Start testing" << std::endl;

	assert(TestCreatePlayer());
	assert(TestWrongDefense());
	assert(TestWrongAttack());

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

