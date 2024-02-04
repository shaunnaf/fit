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
      fwrite(&root->value, sizeof(int), 1, outputFile);
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

void freemem(struct tnode *tree) {
  if (tree != NULL) {
    freemem(tree->left);
    freemem(tree->right);
    free(tree);
  }
}

int main() {
  FILE *inputFile, *outputFile;

  inputFile = fopen("input.bin", "rb");
  if (inputFile == NULL) {
    fprintf(stderr, "Error open file");
    return 1;
  }

  outputFile = fopen("output.bin", "wb");
  if (outputFile == NULL) {
    fprintf(stderr, "Error open file");
    fclose(inputFile);
    return 1;
  }

  int count_numbers;
  fread(&count_numbers, sizeof(int), 1, inputFile);

  tnode *root = malloc(sizeof(tnode));
  srand(time(NULL));

  root->left = NULL;
  root->right = NULL;
  root->count = 0;

  int *array = malloc(sizeof(int) * count_numbers);

  for (int i = 0; i < count_numbers; i++) {
    fread(&array[i], sizeof(int), 1, inputFile);
  }

  for (int i = 0; i < count_numbers; i++) {
    int temp;
    int pos = rand() % (i + 1);
    temp = array[pos];
    array[pos] = array[i];
    array[i] = temp;
  }

  for (int i = 0; i < count_numbers; i++) {
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
