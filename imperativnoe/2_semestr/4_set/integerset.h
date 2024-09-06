#ifndef INTEGERSET_H
#define INTEGERSET_H

typedef struct Node {
  int value;
  struct Node* next;
} Node;

typedef struct {
  Node** buckets;
  int capacity;
} IntegerSet;

IntegerSet* CreateSet(const int* elements, int numElements);
void DeleteSet(IntegerSet* set);
int IsInSet(const IntegerSet* set, int element);

#endif
