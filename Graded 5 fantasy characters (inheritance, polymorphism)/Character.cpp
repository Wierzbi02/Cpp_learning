#include "Character.h"

Character::Character(const std::string& name, int max_health_points) :
	name(name), max_health_points(max_health_points), current_health_points(max_health_points)
{
}

void Character::Attack(Character& character)
{
	if (this->current_health_points > 0) {
		character.TakeDamage(2);
	}
}

void Character::Rest(int hours)
{
	GetHealed(hours);
}

void Character::TakeDamage(int damage)
{
	current_health_points -= damage;
	if (current_health_points < 0) {
		current_health_points = 0;
	}
}

void Character::GetHealed(int heal)
{
	current_health_points += heal;
	if (current_health_points > max_health_points) {
		current_health_points = max_health_points;
	}
}

void Character::Serialize(std::ostream& os) const
{
	os << name << " (HP: " << current_health_points;
	os << '/' << max_health_points << ") ";
}

std::ostream& operator<<(std::ostream& os, const Character& character)
{
	character.Serialize(os);
	return os;
}
