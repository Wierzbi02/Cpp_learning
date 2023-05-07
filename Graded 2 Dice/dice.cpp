#include "dice.h"
unsigned int randomNumberFrom1ToX(unsigned int x)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, x);
    return dist(rnd_generator);
}

const char* Dice::getColor() const
{
    switch (this->color) {
    case Color::red:
        return "red";
    case Color::yellow:
        return "yellow";
    case Color::green:
        return "green";
    case Color::orange:
        return "orange";
    case Color::blue:
        return "blue";
    }

    return "";
}

std::ostream& operator<<(std::ostream& out, const Dice& dice)
{
    
    out << dice.getColor() << " K" << dice.max_number << " with " << dice.current_number << " pips\n";
    return out;
}

unsigned int Dice::last_max_number = 4;

Dice::Dice(Color _color, unsigned int _max_number, unsigned int _current_number) : max_number(_max_number != 0 ? _max_number : last_max_number)
{
    last_max_number = max_number + 1;
    color = _color;
    if (_current_number == 0) {
        current_number = randomNumberFrom1ToX(max_number);
    }
    else if (_current_number < 1) {
        current_number = 1;
    }
    else if (_current_number > max_number) {
        current_number = max_number;
    }
    else {
        current_number = _current_number;
    }
}

Dice& Dice::operator*()
{
    current_number = randomNumberFrom1ToX(max_number);
    return *this;
}

Dice Dice::operator-(Dice dice2) const
{
    unsigned int _max_number;
    unsigned int _current_number;

    if (this->max_number > dice2.max_number) {
        _max_number = this->max_number;
    }
    else {
        _max_number = dice2.max_number;
    }

    if (this->current_number > dice2.current_number) {
        _current_number = this->current_number;
    }
    else {
        _current_number = dice2.current_number;
    }

    if (this->color == Color::orange && dice2.color == Color::yellow) {
        return Dice(Color::red, _max_number, _current_number);
    }
    else if (this->color == Color::orange && dice2.color == Color::red) {
        return Dice(Color::yellow, _max_number, _current_number);
    }
    else if (this->color == Color::green && dice2.color == Color::blue) {
        return Dice(Color::yellow, _max_number, _current_number);
    }
    else if (this->color == Color::green && dice2.color == Color::yellow) {
        return Dice(Color::blue, _max_number, _current_number);
    }
    else {
        return Dice(dice2.color, _max_number, _current_number);
    }
}

Dice& Dice::operator++()
{
    if (current_number == max_number) {
        current_number = 1;
    }
    else {
        ++current_number;
    }
    return *this;
}
