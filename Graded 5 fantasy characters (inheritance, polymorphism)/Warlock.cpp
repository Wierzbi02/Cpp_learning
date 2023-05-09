#include "Warlock.h"
#include "Spell.h"
#include"ArcaneMissilesSpell.h"
#include"HealingTouchSpell.h"

Warlock::Warlock(const std::string& name, int max_health_points, int spell_slots) :
	Character(name, max_health_points), spell_slots(spell_slots), prepared_spells(0), spells(nullptr)
{
	spells = new Spell*[spell_slots];
	for (int i = 0; i < spell_slots; ++i) {
		spells[i] = nullptr;
	}
}

void Warlock::Attack(Character& character)
{
	for (int i = spell_slots - 1; i >= 0; --i) {
		if (spells[i] != nullptr) {
			spells[i]->Cast(*this, character);
			spells[i] = nullptr;
			return;
		}
	}
	Character::Attack(character);
}

void Warlock::Rest(int hours)
{
	Character::Rest(hours);
	Spell* s;
	if (hours % 2 == 0) {
		s = new ArcaneMissilesSpell();
	}
	else {
		s = new HealingTouchSpell();
	}
	for (int i = 0; i < spell_slots; ++i) {
		if (spells[i] == nullptr) {
			spells[i] = s;
			return;
		}
	}
	delete s; //in case no free space in spells
}

Character* Warlock::Clone()
{
	Warlock* cpy = new Warlock(name, max_health_points, spell_slots);
	for (int i = 0; i < spell_slots; ++i) {
		if (spells[i] == nullptr) {
			break;
		}
		else {
			ArcaneMissilesSpell* ams;
			if (ams = dynamic_cast<ArcaneMissilesSpell*>(spells[i])) {
				cpy->spells[i] = new ArcaneMissilesSpell;
			}
			else {
				cpy->spells[i] = new HealingTouchSpell;
			}
		}
	}

	cpy->prepared_spells = this->prepared_spells;

	return cpy;
}

void Warlock::Serialize(std::ostream& os) const
{
	Character::Serialize(os);
	os << "- class: Warlock, prepared spells: ";
	for (int i = 0; i < spell_slots; ++i) {
		if (spells[i] != nullptr) {
			os << *(spells[i]) << ' ';
		}
		else {
			return;
		}
	}
}
