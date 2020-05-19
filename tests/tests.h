//
// Created by egor on 19.05.2020.
//

#ifndef KEYBOARD_NINJA_TESTS_H
#define KEYBOARD_NINJA_TESTS_H

#include "../lib/Game.h"
#include "ctest.h"

CTEST(Syntax, Correct)
{
    int result = InputCheck("1");
    int expected = 1;
ASSERT_EQUAL(expected, result);
}

CTEST(Syntax, Incorrect)
{
    int result = InputCheck("awrqwr");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
CTEST(Syntax, Incorrect)
{
int result = InputCheck("exit");
int expected = 1337;
ASSERT_EQUAL(expected, result);
}
#endif // KEYBOARD_NINJA_TESTS_H
