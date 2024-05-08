#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <stdlib.h>

typedef struct {
  int* elements;
  int size;
} IntegerSet;

IntegerSet* CreateSet(int* array, int size);
int IsInSet(IntegerSet* set, int number);
void DeleteSet(IntegerSet* set);

#endif