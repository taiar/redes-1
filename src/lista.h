#ifndef __LISTA_H
#define __LISTA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <assert.h>

using namespace std;

typedef void (*freeFunction)(void *);
typedef bool (*listIterator)(void *);

class ListNode {
public:
  void *data;
  ListNode *next;
};

class List {
public:
  int logicalLength;
  int elementSize;
  ListNode *head;
  ListNode *tail;
  freeFunction freeFn;

  List(int, freeFunction);
  void destroy();

  void prepend(void*);
  void append(void*);
  int  size();

  void for_each(listIterator);
  void h(void*, bool);
  void t(void*);
};

#endif
