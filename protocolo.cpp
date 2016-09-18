#include "protocolo.h"

int parse(char msg[]) {
  switch (msg[0]) {
    case 'C':
      printf("CCCCCCCC\n");
      break;
    case 'D':
      printf("DDDDDD\n");
      break;
    case 'O':
      printf("OOOOOOOOOOO\n");
      break;
    case 'Z':
      printf("ZZZZZZZZZZZ\n");
      break;
  }
}
