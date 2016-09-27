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
  static int compare(const void*, const void*);

private:
  std::vector<Tempo*> tempos;
  Tempo* orderAndReturnThePosition(int);
};

#endif
