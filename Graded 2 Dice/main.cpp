#include <random>
#include <iostream>

#include "dice.h"
#include "dice_tower.h"

int main() {

    //PART 1
    Dice red_K6(Dice::Color::red, 6, 3);
    Dice yellow_K8(Dice::Color::yellow, 8, 8);
    // handle too big values in parameters
    Dice green_K4(Dice::Color::green, 4, 22);
    // handle defaults
    Dice blue_K4(Dice::Color::blue, 4);
    Dice blue_K5(Dice::Color::blue);
    
    //PART 2
    std::cout << "Dice:" << std::endl;
    std::cout << red_K6 << std::endl;
    std::cout << yellow_K8 << std::endl;
    std::cout << green_K4 << std::endl;
    std::cout << blue_K4 << std::endl;
    std::cout << blue_K5 << std::endl;
    
    //PART 3
    std::cout << std::endl << "Rerolls:" << std::endl;
    std::cout << *red_K6 << std::endl;
    std::cout << *red_K6 << std::endl;
    std::cout << ***yellow_K8 << std::endl;
    std::cout << *green_K4 << std::endl;
    
    //PART 4
    std::cout << std::endl << "Mixing colors:" << std::endl;
    std::cout << (green_K4 - yellow_K8) << std::endl;
    std::cout << (green_K4 - blue_K4) << std::endl;
    std::cout << (blue_K4 - green_K4) << std::endl;
    std::cout << (blue_K4 - red_K6) << std::endl;
    
    //PART 5
    std::cout << std::endl << "Incrementing dice:" << std::endl;
    std::cout << red_K6; 
    std::cout << " incremented: " << ++red_K6 << std::endl;
    std::cout << green_K4;
    std::cout << " incremented: " << ++green_K4 << std::endl;
    std::cout << yellow_K8; 
    std::cout << " incremented: " << ++yellow_K8 << std::endl;
    std::cout << red_K6;
    std::cout << " incremented twice: " << ++++red_K6 << std::endl;
    
    //PART 6
    DiceTower dice_tower;
    std::cout << std::endl << "Dice tower" << std::endl;
    dice_tower.insert(red_K6);
    std::cout << "First dice: " << red_K6 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.insert(yellow_K8);
    std::cout << "Second dice: " << yellow_K8 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.insert(green_K4);
    std::cout << "Third dice: " << green_K4 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.insert(blue_K4);
    std::cout << "Fourth dice: " << blue_K4 << ", result: " << dice_tower.result() << std::endl; 

    //PART 7
    dice_tower.reset();
    dice_tower.insert(red_K6);
    std::cout << "First dice: " << red_K6 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.insert(yellow_K8);
    std::cout << "Second dice: " << yellow_K8 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.insert(green_K4);
    std::cout << "Third dice: " << green_K4 << ", result: " << dice_tower.result() << std::endl; 
    dice_tower.clear();
    dice_tower.insert(blue_K4);
    std::cout << "Fourth dice: " << blue_K4 << ", result: " << dice_tower.result() << std::endl; 

    return 0;
}