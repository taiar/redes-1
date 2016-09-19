#ifndef __SERVIDOR_H
#define __SERVIDOR_H SERVIDOR

struct sockaddr;

void logexit(const char*);
void fill(const struct sockaddr *addr, char *line);

class Servidor {
public:
  void pushTime(char[]);
  void getPosition(char[]);
  void dumpTimes();
  void shutdown();
};

#endif
