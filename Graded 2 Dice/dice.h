#ifndef _DICE_H
#define _DICE_H

#include <random>
#include <iostream>

static const unsigned int SEED = 14321; //intentionally set to constant, for the same "random" results
static std::random_device rd;
static std::mt19937 rnd_generator(SEED);
unsigned int randomNumberFrom1ToX(unsigned int x);


class Dice {
    public:
        enum class Color {
            red, yellow, orange, blue, green
        };
    private:
        // use it to remember the number of the sides of the last created dice
        static unsigned int last_max_number;
        // current value of the dice
        unsigned int current_number;
        //add members:
        // - max_number - number of sides
        const unsigned int max_number;
        // - color
        Color color;
    public:
        unsigned int value() const { return current_number; }
        //add methods...
        Dice(Color _color, unsigned int _max_number = 0, unsigned int _current_number = 0);
        const char* getColor() const;
        friend std::ostream& operator<<(std::ostream& out, const Dice& dice);
        Dice& operator*();
        Dice operator-(Dice dice2) const;
        Dice& operator++();
};

#endif
