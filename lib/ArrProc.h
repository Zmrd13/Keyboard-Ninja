//
// Created by weders on 13.04.2020.
//

#ifndef KEYBOARD_NINJA_ARRPROC_H
#define KEYBOARD_NINJA_ARRPROC_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void ReadLevelFile(const string& path, string* lev)
{
    ifstream file(path);

    string str;

    int i = 0;
    while (getline(file, str, '\n')) {
        lev[i] = str;
        i++;
    }
}

extern string currentArray[100];

void ArrayWrite(string* lev)
{
    for (int i = 0; i < 100; i++) {
        currentArray[i] = lev[i];
    }
}
#endif // KEYBOARD_NINJA_ARRPROC_H
