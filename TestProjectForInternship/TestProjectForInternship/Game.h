#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Game {
	class DamageRange {
		int Min = -1;
		int Max = -1;

	public:
		DamageRange() = delete;
		DamageRange(const DamageRange&&) = delete;

		DamageRange(int min, int max)
			: Min(min), Max(max) {

			if (Min > Max) {
				throw std::invalid_argument("Max value must be greater than Min value");
			}

			if (Min < 0) {
				throw std::invalid_argument("Min value is less than zero");
			}
		}

		DamageRange(const DamageRange& damage)
			: DamageRange(damage.Min, damage.Max) {}

		int GetMin() {
			return Max;
		}

		int GetMax() {
			return Max;
		}
	};

	class Creature {
	protected:
		std::string Name;
		int Defense = -1;
		int Attack = -1;
		int Health = -1;
		int MaxHealth = -1;
		Game::DamageRange DmgRange;

		const int MaxAttackValue = 30;
		const int MaxDefenseValue = MaxAttackValue;

	public:
		Creature() = delete;
		Creature(const Creature&) = delete;
		Creature(const Creature&&) = delete;

		std::string GetName() {
			return Name;
		}

		int GetDefense() {
			return Defense;
		}

		int GetAttack() {
			return Attack;
		}

		int GetHealth() {
			return Health;
		}

		bool IsDead() {
			return Health <= 0;
		}

		void AttackTarget(Creature& target) {
			if (IsDead() || target.IsDead()) {
				return;
			}

			int attackModifier = Attack - target.Defense + 1;

			if (attackModifier < 1) {
				attackModifier = 1;
			}

			std::vector<int> diceRolls;
			for (int i = 0; i < attackModifier; ++i) {
				diceRolls.push_back(rand() % 6 + 1);
			}

			bool successfulAttack = false;
			for (int roll : diceRolls) {
				if (roll == 5 || roll == 6) {
					successfulAttack = true;
					break;
				}
			}

			if (successfulAttack) {
				int damage = rand() % (DmgRange.GetMax() - DmgRange.GetMin() + 1) + DmgRange.GetMin();
				target.TakeDamage(damage);
			}
		}

		void TakeDamage(int damage) {
			Health = std::max(Health - damage, 0);
			std::cout << Name << " takes " << damage << " damage and now has " << Health << " health." << std::endl;
		}

	protected:
		Creature(const std::string& name
			, int attack
			, int defense
			, int health
			, const Game::DamageRange& damage)
			: Name(name), Defense(defense), Health(health), MaxHealth(health), Attack(attack), DmgRange(damage) {

			ValidateParam("Defense", Defense, 1, MaxDefenseValue);
			ValidateParam("Attack", Attack, 1, MaxAttackValue);
		}

		int ValidateParam(const std::string& paramName, int value, int minValue, int maxValue) {
			if (value < minValue || value > maxValue) {
				throw std::invalid_argument(paramName + " must be between " + std::to_string(minValue) + " and " + std::to_string(maxValue));
			}
			return value;
		}
	};

	class Player : public Creature {
	private:
		int HealCount = 0;
		const int MaxHeals = 4;

	public:
		Player(const std::string& name
			, int attack
			, int defense
			, int health
			, const Game::DamageRange& dmgRange)
			: Creature(name, attack, defense, health, dmgRange) {}

		void Heal() {
			if (IsDead()) {
				return;
			}

			if (HealCount >= MaxHeals) {
				return;
			}

			++HealCount;

			int healAmount = static_cast<int>(MaxHealth * 0.3);
			Health = std::min(Health + healAmount, MaxHealth);

			std::cout << Name << " heals for " << healAmount << " health and now has " << Health << " health." << std::endl;
		}
	};

	class Monster : public Creature {
	public:
		Monster(const std::string& name
			, int attack
			, int defense
			, int health
			, const Game::DamageRange& dmgRange)
			: Creature(name, attack, defense, health, dmgRange) {}
	};
}
