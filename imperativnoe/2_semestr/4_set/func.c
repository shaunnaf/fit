#include "integerset.h"

IntegerSet* CreateSet(int* arr, int size) {
  if (size < 0) return NULL;

  IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
  if (!set) return NULL;

  set->elements = (int*)malloc(size * sizeof(int));
  if (!set->elements) {
    free(set);
    return NULL;
  }

  for (int i = 0; i < size; ++i) {
    set->elements[i] = arr[i];
  }

  set->size = size;
  return set;
}

void DeleteSet(IntegerSet* set) {
  if (set) {
    free(set->elements);
    free(set);
  }
}

int IsInSet(IntegerSet* set, int num) {
  if (!set) return 0;

  for (int i = 0; i < set->size; ++i) {
    if (set->elements[i] == num) {
      return 1;
    }
  }
  return 0;
}