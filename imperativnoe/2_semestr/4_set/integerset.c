#include "integerset.h"

#include <math.h>
#include <stdlib.h>

static int hash(int value, int capacity) { return (abs(value) % capacity); }

IntegerSet* CreateSet(const int* elements, int numElements) {
  if (numElements < 0) {
    return NULL;
  }

  IntegerSet* set = (IntegerSet*)malloc(sizeof(IntegerSet));
  if (!set) {
    return NULL;
  }

  if (numElements == 0) {
    set->buckets = NULL;
    set->capacity = 0;
    return set;
  }

  set->buckets = (Node**)calloc(numElements, sizeof(Node*));
  set->capacity = numElements;

  if (set->buckets == NULL) {
    free(set);
    return NULL;
  }

  for (int i = 0; i < numElements; i++) {
    int index = hash(elements[i], numElements);

    Node* current = set->buckets[index];
    while (current != NULL) {
      if (current->value == elements[i]) {
        DeleteSet(set);
        return NULL;
      }
      current = current->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
      DeleteSet(set);
      return NULL;
    }

    newNode->value = elements[i];
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
  }

  return set;
}

void DeleteSet(IntegerSet* set) {
  if (set == NULL || set->buckets == NULL) {
    return;
  }

  for (int i = 0; i < set->capacity; i++) {
    Node* current = set->buckets[i];
    while (current != NULL) {
      Node* next = current->next;
      free(current);
      current = next;
    }
  }

  free(set->buckets);
  free(set);
}

int IsInSet(const IntegerSet* set, int element) {
  if (set == NULL || set->buckets == NULL) {
    return 0;
  }

  int index = hash(element, set->capacity);
  Node* current = set->buckets[index];

  while (current != NULL) {
    if (current->value == element) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

// ассимптотика хеш таблицы,