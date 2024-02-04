#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* next;
  int data;
} Node;

typedef void (*callback)(void* ctx, int* value);

void sumEvenCallback(void* ctx, int* value) {
  int* sum = (int*)ctx;
  if (*value % 2 == 0) {
    *sum += *value;
  }
}

void nodeFreeCallback(void* ctx, int* value) {
  Node* j = (Node*)((char*)value - sizeof(Node*));
  free(j);
}

void arrayForeach(void* ctx, callback func, int* arr, int n) {
  for (int i = 0; i < n; ++i) {
    func(ctx, &arr[i]);
  }
}

void listForeach(void* ctx, callback func, Node* head) {
  Node* current = head;
  while (current != NULL) {
    Node* next = current->next;
    func(ctx, &(current->data));
    current = next;
  }
}

Node* push(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

void freeList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    Node* next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  int count_numbers;
  FILE* mf = NULL;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error_open_file");
    return -1;
  }
  if (fscanf(mf, "%d", &count_numbers) != 1) {
    fprintf(stderr, "error_read_count");
    return -1;
  }

  int* array = (int*)malloc(count_numbers * sizeof(int));
  Node* list = NULL;

  for (int i = 0; i < count_numbers; ++i) {
    int value;
    if (fscanf(mf, "%d", &value) != 1) {
      fprintf(stderr, "error_input");
      return -1;
    }
    array[i] = value;
    list = push(list, value);
  }

  int sumArray = 0;
  arrayForeach(&sumArray, sumEvenCallback, array, count_numbers);

  int sumList = 0;
  listForeach(&sumList, sumEvenCallback, list);

  printf("%d %d\n", sumArray, sumList);

  free(array);
  listForeach(0, nodeFreeCallback, list);

  return 0;
}
