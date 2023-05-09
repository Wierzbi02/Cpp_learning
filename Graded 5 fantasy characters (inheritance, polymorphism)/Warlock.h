#pragma once

#include <ostream>
#include "Character.h"

class Spell;

class Warlock : public Character {

protected:
    Spell** spells;
    int spell_slots;
    int prepared_spells;

public:
    Warlock() = delete;
    Warlock(const Warlock& warlock) = delete;
    Warlock& operator=(const Warlock& warlock) = delete;

    Warlock(const std::string& name, int max_health_points, int spell_slots);

    void Attack(Character& character);
    void Rest(int hours);
    //void TakeDamage(int damage);
    //void GetHealed(int heal);
    Character* Clone();
protected:
    void Serialize(std::ostream& os) const;
};
