#include <stdio.h>

#define MOD 1000000007

int main() {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");

  int number;
  fscanf(input, "%d", &number);

  int count_decomp[number + 1];
  count_decomp[0] = 1;

  for (int i = 1; i <= number; i++) {
    count_decomp[i] = 0;
  }

  for (int i = 1; i <= number; i++) {
    for (int j = i; j <= number; j++) {
      count_decomp[j] = (count_decomp[j] + count_decomp[j - i]) % MOD;
    }
  }

  fprintf(output, "%d\n", count_decomp[number]);

  fclose(input);
  fclose(output);

  return 0;
}
