#include <assert.h>

#include "modular.h"  //в этом хедере должны быть объявления

int main() {
  MOD = 13;  // устанавливаем глобальный модуль
  int a = 34;
  a = pnorm(a);
  int x = pmul(padd(7, psub(2, 3)), 5);
  assert(x == 4);
  int y = pdiv(7, x);
  assert(pmul(x, y) == 7);
  MOD = 3;  // меняем модуль на другой
  assert(pnorm(113) == 2);
  assert(pnorm(-15) == 0);
  MOD = 5;
  assert(pnorm(0) == 0);
  assert(pnorm(-16) == 4);
  assert(padd(4, 4) == 3);
  assert(psub(2, 4) == 3);
  MOD = 1000003;
  assert(pmul(100000, 100000) == 970003);
  MOD = 1000000007;
  assert(pdiv(104430, 5437) == 629391232);

  return 0;
}
