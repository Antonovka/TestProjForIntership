#pragma once

#include <iostream>
#include <string>

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
		std::string Name;
		int Defense = -1;
		int Attack = -1;
		int Health = -1;
		int MaxHealth = -1;
		Game::DamageRange DmgRange;

		int HealCount = 0;

		const int MaxAttackValue = 30;
		const int MaxDefenseValue = MaxAttackValue;
		const int MaxHeals = 4;

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

		bool IsDead() {
			return Health <= 0;
		}

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
		}

		void AttackTarget(Creature& target) {
			int attackModifier = DmgRange.GetMax() - target.Defense + 1;
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
	public:
		Player(const std::string& name
			, int attack
			, int defense
			, int health
			, const Game::DamageRange& dmgRange)
			: Creature(name, attack, defense, health, dmgRange) {}
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
