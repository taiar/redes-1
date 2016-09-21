#ifndef __TEMPO_H
#define __TEMPO_H TEMPO

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "token.h"

using namespace std;

class Tempo {
public:
  int hours;
  int minutes;
  int seconds;
  int milisseconds;

  Tempo();
  Tempo(int, int, int, int);
  int compare(Tempo);
  Tempo* setFromString(char[]);
  string toString();
  void print();
};

#endif
