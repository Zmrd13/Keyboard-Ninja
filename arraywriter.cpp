//
// Created by weders on 10.04.2020.
//

#include "arraywriter.h"
#include <iostream>

extern string current_array[100];
void array_writer(string *lev) {
  for (int i = 0; i < 100; i++) {
    current_array[i] = lev[i];
  }
}