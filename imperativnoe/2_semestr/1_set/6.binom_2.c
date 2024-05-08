#include <stdio.h>

#define MOD 1000000007
#define MAXCOUNT 1000001

long long factorial[MAXCOUNT];
long long inverse_factorial[MAXCOUNT];

void init(void);
int check_module(int number_a, int module);
long long mod_pow(long long a, long long n);
long long lucas(long long n, long long k);

int main() {
  FILE *mf, *mf2;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error open file");
    return 1;
  }
  int count_tests, n, k;
  if (fscanf(mf, "%d", &count_tests) != 1) {
    fprintf(stderr, "error_input");
    return 1;
  }
  mf2 = fopen("output.txt", "w");
  for (int i = 0; i < count_tests; i++) {
    if (fscanf(mf, "%d %d", &n, &k) != 2) {
      fprintf(stderr, "error_input");
      return 1;
    }
    init();
    if (k > n || k < 0) {
      fprintf(mf2, "0\n");
    } else {
      fprintf(mf2, "%lld\n", lucas(n, k));
    }
  }
  fclose(mf2);
  fclose(mf);
  return 0;
}

int check_module(int number_a, int module) {
  int module_copy = module;
  int temp, delenie;
  int x0 = 0;
  int x1 = 1;

  if (module == 1 || number_a == 0) return -1;

  while (number_a > 1) {
    delenie = number_a / module;
    temp = module;
    module = number_a % module;
    number_a = temp;
    temp = x0;
    x0 = x1 - delenie * x0;
    x1 = temp;
  }

  while (x1 < 0) x1 += module_copy;

  return x1;
}

long long mod_pow(long long a, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      result = (result * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return result;
}

void init(void) {
  factorial[0] = 1;
  inverse_factorial[0] = 1;
  for (int i = 1; i < MAXCOUNT; ++i) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
    inverse_factorial[i] = mod_pow(factorial[i], MOD - 2);
  }
}

long long lucas(long long n, long long k) {
  if (k == 0) {
    return 1;
  }
  long long result = (factorial[n] * inverse_factorial[k]) % MOD;
  result = (result * inverse_factorial[n - k]) % MOD;
  return result;
}

// факториалы