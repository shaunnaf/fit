#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int mul(long first_param, long second_param);
long long int add(long first_param, long second_param);
long long int sub(long first_param, long second_param);
int parsing_string(char *argv[], long long int *answer, int *curr_argv,
                   long *modul);

int main(int argc, char *argv[]) {
  int curr_argv = 1;
  long modul = -1;
  long long int answer;
  if (argc == curr_argv || parsing_string(argv, &answer, &curr_argv, &modul)) {
    fprintf(stderr, "No parameters specified.");
    return 13;
  }
  if (curr_argv < argc) {
    if (parsing_string(argv, &answer, &curr_argv, &modul)) {
      fprintf(stderr, "No parameters specified.");
      return 13;
    } else {
      answer %= modul;
      if (answer < 0) {
        answer += modul;
      }
      printf("%lld", answer);
    }
  } else {
    printf("%lld", answer);
  }
  return 0;
}

int parsing_string(char *argv[], long long int *answer, int *curr_argv,
                   long *modul) {
  if (strcmp(argv[*curr_argv], "mul") == 0) {
    long first_param = strtol(argv[*(curr_argv) + 1], 0, 10);
    long second_param = strtol(argv[*(curr_argv) + 2], 0, 10);
    *answer = mul(first_param, second_param);
    *curr_argv += 3;
  } else if (strcmp(argv[*curr_argv], "add") == 0) {
    long first_param = strtol(argv[*(curr_argv) + 1], 0, 10);
    long second_param = strtol(argv[*(curr_argv) + 2], 0, 10);
    *answer = add(first_param, second_param);
    *curr_argv += 3;
  } else if (strcmp(argv[*curr_argv], "sub") == 0) {
    long first_param = strtol(argv[*(curr_argv) + 1], 0, 10);
    long second_param = strtol(argv[*(curr_argv) + 2], 0, 10);
    *answer = sub(first_param, second_param);
    *curr_argv += 3;
  } else if (strcmp(argv[*curr_argv], "-m") == 0) {
    *modul = strtol(argv[*(curr_argv) + 1], 0, 10);
    *curr_argv += 2;
  } else {
    return 13;
  }
  return 0;
}

long long int mul(long first_param, long second_param) {
  long long int answer = first_param * second_param;
  return answer;
}

long long int add(long first_param, long second_param) {
  long long int answer = first_param + second_param;
  return answer;
}

long long int sub(long first_param, long second_param) {
  long long int answer = first_param - second_param;
  return answer;
}