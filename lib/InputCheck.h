//
// Created by egor on 20.05.2020.
//

#ifndef KEYBOARD_NINJA_INPUTCHECK_H
#define KEYBOARD_NINJA_INPUTCHECK_H
#include <string>
int InputCheck(std::string getLevelNumber)
{
    int Number = 0;
    if (getLevelNumber == "exit") {
        exit(1);
    }
    if (atoi(getLevelNumber.c_str()) == 0) {

        return 0;
    }
    Number = atoi(getLevelNumber.c_str()); //

    return Number;
}
#endif // KEYBOARD_NINJA_INPUTCHECK_H
