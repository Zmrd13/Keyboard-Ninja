//
// Created by weders on 13.04.2020.
//

#ifndef KEYBOARD_NINJA_ARRPROC_H
#define KEYBOARD_NINJA_ARRPROC_H

#include <fstream>
#include <iostream>
#include <string>
#include "LevelFileReader.h"

using namespace std;

void ReadLevelFile(const string& path, string* words)
{
    ifstream file(path);
    LevelFileReader fileReader(file);

    for (int i = 0; true; i++)
    {
      string str = fileReader.GetWord();
      if (str == "") break;
      words[i] = str;
    }

    return;
}

extern string currentArray[100];

void ArrayWrite(string* lev)
{
    for (int i = 0; i < 100; i++) {
        currentArray[i] = lev[i];
    }
}
#endif // KEYBOARD_NINJA_ARRPROC_H
