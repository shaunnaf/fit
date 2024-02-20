#include "modular.h"  //в этом хедере должны быть объявления

int pnorm(int number) { return (number % MOD + MOD) % MOD; }

int padd(int number1, int number2) {
  return pnorm(pnorm(number1) + pnorm(number2));
}

int psub(int number1, int number2) {
  return pnorm(pnorm(number1) - pnorm(number2));
}

int pmul(int number1, int number2) {
  unsigned long long ans = (unsigned long long)pnorm(number1) * pnorm(number2);
  return pnorm((int)(ans % MOD));
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

int pdiv(int number1, int number2) {
  int inv = check_module(pnorm(number2), MOD);
  if (inv == -1) {
    return -1;
  }
  return pmul(number1, inv);
}
