//
// Created by weders on 13.04.2020.
//
#include <fstream>

#include <iostream>
#include <string>
using namespace std;
void readLevelFile(const string& path, string* lev)
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

void arrayWrite(string* lev)
{
    for (int i = 0; i < 100; i++) {
        currentArray[i] = lev[i];
    }
}