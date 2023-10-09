#include <iostream>
#include <assert.h>

#include "Game.h"

using namespace std;

bool TestCreatePlayer();

int main() {
	Game::DamageRange damageRange (0, 10);
	Game::Player player ("Player", 12, 100, 2, damageRange);

	std::cout << "Start testing" << std::endl;

	assert(TestCreatePlayer());
	return 0;
}

bool TestCreatePlayer() {
	std::cout << "TestCreatePlayer" << std::endl;

	std::string name = "Player";
	int attack = 10;
	int defense = 10;
	int health = 10;
	Game::DamageRange damageRange(0, 10);

	Game::Player player(name, attack, defense, health, damageRange);

	if (player.GetName().compare(name) != 0) {
		return false;
	}

	if (player.GetName().compare(name) != 0) {
		return false;
	}

	if (player.GetDefense() != 0) {
		return false;
	}

	return true;
}