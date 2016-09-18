#ifndef SERVIDOR
#define SERVIDOR SERVIDOR

  struct sockaddr;

  void logexit(const char*);
  void fill(const struct sockaddr *addr, char *line);

#endif
