#include "HealingTouchSpell.h"
#include "Character.h"

void HealingTouchSpell::Cast(Character& caster, Character& target)
{
	target.GetHealed(HEALING);
}

void HealingTouchSpell::Serialize(std::ostream& os) const
{
	os << "HealingTouchSpell";
}
