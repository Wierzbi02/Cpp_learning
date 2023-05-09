#include "ArcaneMissilesSpell.h"
#include "Character.h"

void ArcaneMissilesSpell::Cast(Character& caster, Character& target)
{
	for (int i = 0; i < MISSILES_COUNT; ++i) {
		target.TakeDamage(DAMAGE);
	}
}

void ArcaneMissilesSpell::Serialize(std::ostream& os) const
{
	os << "ArcaneMissilesSpell";
}
