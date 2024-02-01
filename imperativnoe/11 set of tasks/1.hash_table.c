#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000003

typedef struct Node {
  int value;
  struct Node* next;
} Node;

typedef struct {
  Node* table[HASH_TABLE_SIZE];
} HashTable;

void initHashTable(HashTable* ht);
void addToHashTable(HashTable* ht, int value);
int isInHashTable(HashTable* ht, int value);

int main() {
  int count_numbers;
  FILE* mf = NULL;
  mf = fopen("input.bin", "rb");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return -1;
  }
  fread(&count_numbers, sizeof(int32_t), 1, mf);

  HashTable ht;
  initHashTable(&ht);

  int uniqueCount = 0;
  int* array = malloc(count_numbers * sizeof(int));

  for (int i = 0; i < count_numbers; i++) {
    int num;
    fread(&num, sizeof(int32_t), 1, mf);

    if (!isInHashTable(&ht, num)) {
      addToHashTable(&ht, num);
      array[uniqueCount] = num;
      uniqueCount++;
    }
  }
  fclose(mf);
  mf = fopen("output.bin", "wb");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return -1;
  }
  fwrite(&uniqueCount, sizeof(int), 1, mf);

  for (int i = 0; i < uniqueCount; i++) {
    Node* current = ht.table[abs(array[i]) % HASH_TABLE_SIZE];
    fwrite(&current->value, sizeof(int), 1, mf);
    ht.table[abs(array[i]) % HASH_TABLE_SIZE] = current->next;
  }
  free(array);
  fclose(mf);

  return 0;
}

void initHashTable(HashTable* ht) {
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    ht->table[i] = NULL;
  }
}

void addToHashTable(HashTable* ht, int value) {
  int index = abs(value) % HASH_TABLE_SIZE;
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;

  if (ht->table[index] == NULL) {
    ht->table[index] = newNode;
  } else {
    Node* current = ht->table[index];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

int isInHashTable(HashTable* ht, int value) {
  int index = abs(value) % HASH_TABLE_SIZE;
  Node* current = ht->table[index];
  while (current != NULL) {
    if (current->value == value) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}
