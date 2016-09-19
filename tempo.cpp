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

void Tempo::setFromString(string timeString) {

}
