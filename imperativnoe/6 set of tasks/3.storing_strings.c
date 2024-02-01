#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100000

struct String {
  char *content;
  int length;
};

void createString(FILE *mf2, struct String *strings, int *stringCount,
                  int length, char *content) {
  strings[*stringCount].content = malloc(length + 1);
  strcpy(strings[*stringCount].content, content);
  strings[*stringCount].length = length;
  (*stringCount)++;
}

void deleteString(struct String *strings, int index) {
  if (strings[index].content != NULL) {
    free(strings[index].content);
    strings[index].content = NULL;
  }
}

void printString(FILE *mf2, struct String *strings, int index) {
  fprintf(mf2, "%s\n", strings[index].content);
}

void countChar(FILE *mf2, struct String *strings, int index, char ch) {
  int count = 0;
  for (int i = 0; i < strings[index].length; i++) {
    if (strings[index].content[i] == ch) {
      count++;
    }
  }
  fprintf(mf2, "%d\n", count);
}

int main() {
  int n;
  FILE *mf = fopen("input.txt", "r");
  FILE *mf2 = fopen("output.txt", "w");

  if (mf == NULL || mf2 == NULL) {
    fprintf(stderr, "Error opening files.\n");
    return 1;
  }

  fscanf(mf, "%d", &n);

  struct String strings[MAX_STRING_LEN];
  int stringCount = 0;

  for (int i = 0; i < n; i++) {
    int type;
    fscanf(mf, "%d ", &type);

    if (type == 0) {
      int length = 0;
      char content[MAX_STRING_LEN];
      fscanf(mf, "%d %s", &length, content);
      createString(mf2, strings, &stringCount, length, content);
    } else if (type == 1) {
      int index;
      fscanf(mf, "%d", &index);
      deleteString(strings, index);
    } else if (type == 2) {
      int index;
      fscanf(mf, "%d", &index);
      printString(mf2, strings, index);
    } else if (type == 3) {
      int index;
      char ch;
      fscanf(mf, "%d %c", &index, &ch);
      countChar(mf2, strings, index, ch);
    }
  }

  for (int i = 0; i < stringCount; i++) {
    free(strings[i].content);
  }
  fclose(mf);
  fclose(mf2);

  return 0;
}
