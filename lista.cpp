#include "lista.h"

List::List(int elementSize, freeFunction freeFn) {
  assert(elementSize > 0);
  this->logicalLength = 0;
  this->elementSize = elementSize;
  this->head = NULL;
  this->tail = NULL;
  this->freeFn = freeFn;
}

void List::destroy() {
  ListNode *current;
  while(this->head != NULL) {
    current = this->head;
    this->head = current->next;

    if(this->freeFn) {
      this->freeFn(current->data);
    }

    free(current->data);
    free(current);
  }
}

void List::prepend(void *element) {
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  node->data = malloc(this->elementSize);
  memcpy(node->data, element, this->elementSize);

  node->next = this->head;
  this->head = node;

  if(!this->tail) {
    this->tail = this->head;
  }

  this->logicalLength++;
}

void List::append(void *element) {
  ListNode *node = (ListNode*) malloc(sizeof(ListNode));
  node->data = malloc(this->elementSize);
  node->next = NULL;

  memcpy(node->data, element, this->elementSize);
  if(this->logicalLength == 0) {
    this->head = this->tail = node;
  } else {
    this->tail->next = node;
    this->tail = node;
  }

  this->logicalLength++;
}

void List::for_each(listIterator iterator) {
  assert(iterator != NULL);
  ListNode *node = this->head;
  bool result = true;
  while(node != NULL && result) {
    result = iterator(node->data);
    node = node->next;
  }
}

void List::h(void *element, bool removeFromList) {
  assert(this->head != NULL);

  ListNode *node = this->head;
  memcpy(element, node->data, this->elementSize);
  if(removeFromList) {
    this->head = node->next;
    this->logicalLength--;
    free(node->data);
    free(node);
  }
}

void List::t(void *element) {
  assert(this->tail != NULL);
  ListNode *node = this->tail;
  memcpy(element, node->data, this->elementSize);
}

int List::size() {
  return this->logicalLength;
}
