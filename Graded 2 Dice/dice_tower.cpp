#include <iostream>
#include "dice_tower.h"

void DiceTower::insert(Dice d)
{
	*d;
	if (dice[0] == nullptr)
		dice[0] = &d;
	else if (dice[1] == nullptr)
		dice[1] = &d;
	else {
		int rand = randomNumberFrom1ToX(3);
		if (rand == 1) {
			sum += dice[0]->value();
			dice[0] = &d;
		}
		else if (rand == 2) {
			sum += dice[1]->value();
			dice[1] = &d;
		}
		else {
			sum += d.value();
		}
	}
}

DiceTower::DiceTower() : sum(0)
{
	dice[0] = nullptr;
	dice[1] = nullptr;
}

void DiceTower::clear()
{
	sum = 0;
}

void DiceTower::reset()
{
	clear();
	dice[0] = nullptr;
	dice[1] = nullptr;
}

int DiceTower::result()
{
	return sum;
}