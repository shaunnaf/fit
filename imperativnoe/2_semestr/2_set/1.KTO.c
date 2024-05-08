#include <stdio.h>
#include <stdlib.h>

long long int modMul(long long int a, long long int b, long long int mod);
long long int gcd(long long int a, long long int b);
long long int fastpow(long long int base, long long int exponent,
                      long long int mod);
long long int eyler(long long int n);
long long int china(long long int* ost, long long int* mod, long long int k);

int main() {
  FILE* mf;
  mf = fopen("input.txt", "r");
  if (mf == NULL) {
    fprintf(stderr, "error open file");
    return 1;
  }
  long long int k;
  if (fscanf(mf, "%lld", &k) != 1) {
    fprintf(stderr, "error_input");
    fclose(mf);
    return 1;
  }
  long long int* mod = malloc(sizeof(long long int) * k);
  long long int* ost = malloc(sizeof(long long int) * k);
  for (long long int i = 0; i < k; i++) {
    if (fscanf(mf, "%lld", &mod[i]) != 1) {
      fprintf(stderr, "error_input");
      free(ost);
      free(mod);
      fclose(mf);
      return 1;
    }
  }
  for (long long int i = 0; i < k; i++) {
    if (fscanf(mf, "%lld", &ost[i]) != 1) {
      fprintf(stderr, "error_input");
      free(ost);
      free(mod);
      fclose(mf);
      return 1;
    }
  }
  long long int result = china(ost, mod, k);
  printf("%lld\n", result);

  free(mod);
  free(ost);
  fclose(mf);

  return 0;
}

long long int modMul(long long int a, long long int b, long long int mod) {
  return ((a % mod) * (b % mod)) % mod;
}

long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}

long long int fastpow(long long int base, long long int exponent,
                      long long int mod) {
  long long int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exponent /= 2;
  }
  return result;
}

long long int eyler(long long int n) {
  long long int result = n;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      result -= result / i;
    }
  }
  if (n > 1) {
    result -= result / n;
  }
  return result;
}

long long int china(long long int* ost, long long int* mod, long long int k) {
  long long int M = 1;
  long long int mi, inverse_mi;
  for (long long int i = 0; i < k; i++) {
    M *= mod[i];
  }
  long long int ans = 0;
  for (long long int i = 0; i < k; i++) {
    mi = M / mod[i];
    inverse_mi = fastpow(mi % mod[i], eyler(mod[i]) - 1, mod[i]);
    ans += modMul(ost[i], inverse_mi, mod[i]) * mi;
    ans %= M;
  }
  return ans;
}