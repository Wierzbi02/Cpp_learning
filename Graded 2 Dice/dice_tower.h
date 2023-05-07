#ifndef _DICE_TOWER_H
#define _DICE_TOWER_H

#include "dice.h"

class DiceTower {
	Dice* dice[2];
	int sum;
public:
	DiceTower();
	void insert(Dice d);
	int result();
	void clear();
	void reset();
};

#endif
