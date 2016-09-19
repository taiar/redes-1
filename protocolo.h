#ifndef __PROTOCOLO_H
#define __PROTOCOLO_H PROTOCOLO

#include <vector>

#include <stdio.h>
#include "servidor.h"

class Protocolo {
public:
  Servidor *serverInstance;

  Protocolo(Servidor*);
  int parse(char[]);
};

#endif
