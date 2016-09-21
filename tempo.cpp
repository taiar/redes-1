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
  cout << t->getToken();
  for(int i = 1; i < t->total(); i += 1) {
    cout << t->getNextToken();
  }

  return this;
}

string Tempo::toString() {
  stringstream s;
  s << this->hours << "h " << this->minutes << "m " << this->seconds << "s " << this->milisseconds << "ms";
  s.str();
}

void Tempo::print() {
  cout << this->toString();
}
