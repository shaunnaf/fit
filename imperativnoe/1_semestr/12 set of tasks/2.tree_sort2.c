#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tnode {
  int value;
  int count;
  struct tnode *left;
  struct tnode *right;
} tnode;

void inOrderTraversal(struct tnode *root, FILE *outputFile) {
  if (root != NULL) {
    inOrderTraversal(root->left, outputFile);
    for (int i = 0; i < root->count; i++) {
      fprintf(outputFile, "%d ", root->value);
    }
    inOrderTraversal(root->right, outputFile);
  }
}

void insert(tnode *root, int value) {
  if (value == root->value) {
    root->count++;
  } else if (value < root->value) {
    if (root->left == NULL) {
      root->left = malloc(sizeof(tnode));
      (root->left)->count = 1;
      (root->left)->value = value;
      (root->left)->left = NULL;
      (root->left)->right = NULL;
    } else {
      insert(root->left, value);
    }
  } else {
    if (root->right == NULL) {
      root->right = malloc(sizeof(tnode));
      (root->right)->count = 1;
      (root->right)->value = value;
      (root->right)->left = NULL;
      (root->right)->right = NULL;
    } else {
      insert(root->right, value);
    }
  }
}

void freemem(struct tnode *root) {
  if (root != NULL) {
    freemem(root->left);
    freemem(root->right);
    free(root);
  }
}

int main() {
  FILE *inputFile, *outputFile;

  inputFile = fopen("input.txt", "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error open file");
    return 1;
  }

  outputFile = fopen("output.txt", "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Error open file");
    fclose(inputFile);
    return 1;
  }

  int n;
  fscanf(inputFile, "%d", &n);

  tnode *root = malloc(sizeof(tnode));
  srand(time(NULL));

  root->left = NULL;
  root->right = NULL;
  root->count = 0;

  int *array = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    fscanf(inputFile, "%d", &array[i]);
  }

  for (int i = 0; i < n; i++) {
    int temp;
    int pos = rand() % (i + 1);
    temp = array[pos];
    array[pos] = array[i];
    array[i] = temp;
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      root->count++;
      root->value = array[i];
    } else {
      insert(root, array[i]);
    }
  }

  inOrderTraversal(root, outputFile);

  freemem(root);

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
