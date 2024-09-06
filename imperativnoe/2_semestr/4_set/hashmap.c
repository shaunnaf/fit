#include "hashmap.h"

#include <stdlib.h>

attribute((visibility("default")));
HashMap HM_Init(EqualFunc ef, HashFunc hf, int size) {
  HashMap map;
  map.array = (Node**)calloc(size, sizeof(Node*));
  map.size = size;
  map.equal = ef;
  map.hash = hf;
  return map;
}

attribute((visibility("default")));
void HM_Destroy(HashMap* self) {
  for (int i = 0; i < self->size; ++i) {
    Node* current = self->array[i];
    while (current != NULL) {
      Node* next = current->next;
      free(current);
      current = next;
    }
  }
  free(self->array);
}

attribute((visibility("default")));
const void* HM_Get(const HashMap* self, cpvoid key) {
  if (self->array == NULL) {
    return NULL;
  }
  uint32_t index = self->hash(key) % self->size;
  Node* current = self->array[index];
  while (current != NULL) {
    if (self->equal(current->key, key)) {
      return current->value;
    }
    current = current->next;
  }
  return NULL;
}

attribute((visibility("default")));

void HM_Set(HashMap* self, cpvoid key, cpvoid value) {
  uint32_t index = self->hash(key) % self->size;
  Node* current = self->array[index];
  Node* prev = NULL;
  while (current != NULL) {
    if (self->equal(current->key, key)) {
      current->value = value;
      return;
    }
    prev = current;
    current = current->next;
  }
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  if (prev == NULL) {
    self->array[index] = newNode;
  } else {
    prev->next = newNode;
  }
}