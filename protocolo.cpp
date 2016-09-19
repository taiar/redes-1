#include "protocolo.h"

Protocolo::Protocolo(Servidor *s) {
  this->serverInstance = s;
}

int Protocolo::parse(char msg[]) {
  switch (msg[0]) {
    case 'C':
      serverInstance->getPosition(msg);
      break;
    case 'D':
      serverInstance->pushTime(msg);
      break;
    case 'O':
      serverInstance->dumpTimes();
      break;
    case 'Z':
      serverInstance->shutdown();
      break;
  }
}
