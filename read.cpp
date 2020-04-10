//
// Created by weders on 10.04.2020.
//

#include "read.h"
#include <fstream>
#include <iostream>
using namespace std;
void read(const string &path, string *lev) {

  ifstream file(path);

  string str;

  int i = 0;
  while (getline(file, str, '\n')) {

    lev[i] = str;
    i++;
  }
}