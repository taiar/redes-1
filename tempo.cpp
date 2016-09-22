#include "tempo.h"

using namespace std;

Tempo::Tempo() {
  this->hours = 0;
  this->minutes = 0;
  this->seconds = 0;
  this->milisseconds = 0;
}

Tempo::Tempo(int h, int m, int s, int ms) {
  this->hours = h;
  this->minutes = m;
  this->seconds = s;
  this->milisseconds = ms;
}

Tempo* Tempo::setFromString(char msg[]) {
  string message(msg);
  Token *t = new Token(message);
  for(int i = 1; i < t->total(); i += 1)
    this->parseUnit(t->getNextToken());
  return this;
}

string Tempo::toString() {
  stringstream s;
  s << this->hours << "h " << this->minutes << "m " << this->seconds << "s " << this->milisseconds << "ms";
  return s.str();
}

void Tempo::print() {
  cout << this->toString();
}

void Tempo::parseUnit(string s) {
  string number;
  string timeUnit;

  for(int i = 0; i < s.size(); i += 1)
    this->isNumber(s[i]) ? number += s[i] : timeUnit += s[i];
  this->setTimeUnit(number, timeUnit);
}

bool Tempo::isNumber(char c) {
  return (isdigit(c) != 0);
}

void Tempo::setTimeUnit(string number, string timeUnit) {
  int intNumber = atoi(number.c_str());

  if(timeUnit == "h")
    this->hours = intNumber;
  else if(timeUnit == "m")
    this->minutes = intNumber;
  else if(timeUnit == "s")
    this->seconds = intNumber;
  else if(timeUnit == "ms")
    this->milisseconds = intNumber;
}

bool Tempo::biggerThan(Tempo t) {
  if(this->hours > t.hours) return true;
  else if(this->minutes > t.minutes) return true;
  else if(this->seconds > t.seconds) return true;
  else if(this->milisseconds > t.milisseconds) return true;
  return false;
}
