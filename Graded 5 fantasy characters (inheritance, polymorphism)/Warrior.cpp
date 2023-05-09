#include "Warrior.h"

Warrior::Warrior(const std::string& name, int max_health_points, int shield_durability) : Character(name, max_health_points),
shield_durability(shield_durability)
{
}

void Warrior::Attack(Character& character)
{
	Warrior* a;
	if (a = dynamic_cast<Warrior*>(&character)) {
		while (a->shield_durability > 0) {
			Character::Attack(character);
		}
	}
	Character::Attack(character);
}

void Warrior::Rest(int hours)
{
	++max_health_points;
	Character::Rest(hours);
}

void Warrior::TakeDamage(int damage)
{
	if (shield_durability > 0) {
		--shield_durability;
		return;
	}

	Character::TakeDamage(damage);
}

void Warrior::Serialize(std::ostream& os) const
{
	Character::Serialize(os);
	os << "class: Warrior(" << shield_durability << ')';
}
