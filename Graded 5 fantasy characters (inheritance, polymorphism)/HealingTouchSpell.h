#pragma once

#include "Spell.h"


class HealingTouchSpell : public Spell {
    static const int HEALING = 8;

    void Cast(Character& caster, Character& target);
    void Serialize(std::ostream& os) const;
};
