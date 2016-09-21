#ifndef __SERVIDOR_H
#define __SERVIDOR_H SERVIDOR

#include <vector>
#include <string>
#include "tempo.h"

struct sockaddr;

void logexit(const char*);
void fill(const struct sockaddr *addr, char *line);

class Servidor {
public:
  void pushTime(char[]);
  void getPosition(char[]);
  void dumpTimes();
  void shutdown();

private:
  std::vector<Tempo*> tempos;
};

#endif