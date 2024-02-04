#include <stdio.h>
#include <string.h>

void print_param(FILE* mf2, char str[], int lenght_param);
void parsing_string(FILE* mf2, char string[]);

int main() {
  char string[110];
  FILE* mf;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    return 1;
  }
  if (fgets(string, sizeof(string), mf) == NULL) {
    return 2;
  }
  fclose(mf);

  mf = fopen("output.txt", "w");
  char* newline = strchr(string, '\n');
  if (newline != NULL) {
    *newline = '\0';
  }

  parsing_string(mf, string);
  fclose(mf);
  return 0;
}

void parsing_string(FILE* mf2, char string[]) {
  int lenght_string = strlen(string);
  char param[110];
  int lenght_param = 0;
  int in_param = 0;
  for (int i = 0; i < lenght_string; i++) {
    if (string[i] == 34) {
      if (in_param) {
        print_param(mf2, param, lenght_param);
        lenght_param = 0;
        in_param = 0;
      } else {
        in_param = 1;
      }
    } else if (in_param) {
      param[lenght_param] = string[i];
      lenght_param += 1;
    } else if (string[i] == 32) {
      continue;
    } else {
      while ((string[i] != 32) && i < lenght_string) {
        param[lenght_param] = string[i];
        i += 1;
        lenght_param += 1;
      }
      print_param(mf2, param, lenght_param);
      lenght_param = 0;
    }
  }
}

void print_param(FILE* mf2, char str[], int lenght_param) {
  fprintf(mf2, "[");
  for (int i = 0; i < lenght_param; i++) {
    fprintf(mf2, "%c", str[i]);
  }
  fprintf(mf2, "]\n");
}