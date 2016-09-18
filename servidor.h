#ifndef __SERVIDOR_H
#define __SERVIDOR_H SERVIDOR

  struct sockaddr;

  void logexit(const char*);
  void fill(const struct sockaddr *addr, char *line);

#endif
