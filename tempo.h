#ifndef __TEMPO_H
#define __TEMPO_H TEMPO

class Tempo {
public:
  int hours;
  int minutes;
  int seconds;
  int milisseconds;

  Tempo();
  Tempo(int, int, int, int);
  int compare(Tempo);
  void setFromString(char*);
};

#endif
