#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "integerset.h"

START_TEST(test) {
  int myarr[] = {1, 2, 3};
  // create set with numbers 1, 2, and 3
  IntegerSet* s123 = CreateSet(myarr, 3);
  myarr[1] = -5;
  ck_assert_int_eq(IsInSet(s123, 3), 1);
  ck_assert_int_eq(IsInSet(s123, 2), 1);
  ck_assert_int_eq(IsInSet(s123, 0), 0);
  ck_assert_int_eq(IsInSet(s123, 4), 0);
  DeleteSet(s123);  // set is destroyed, all used resources should be released
  // create set with numbers -5 and 3
  IntegerSet* s15 = CreateSet(myarr + 1, 2);
  ck_assert_int_eq(IsInSet(s15, 3), 1);
  ck_assert_int_eq(IsInSet(s15, -5), 1);
  ck_assert_int_eq(IsInSet(s15, 1), 0);
  ck_assert_int_eq(IsInSet(s15, 2), 0);
  DeleteSet(s15);  // set is destroyed
  // create empty set (note: null pointer is allowed only when size is 0)
  IntegerSet* sEmpty = CreateSet(0, 0);
  ck_assert_int_ne(IsInSet(sEmpty, 0), 0);
  ck_assert_int_ne(IsInSet(sEmpty, -123456789), 0);

  DeleteSet(sEmpty);  // set is destroyed
  IntegerSet* sNull = 0;
  // null pointer must be treated by IsInSet as empty set
  ck_assert_int_ne(IsInSet(sNull, 0), 0);
  ck_assert_int_ne(IsInSet(sNull, -123456789), 0);

  myarr[0] = -5;
  // if array has equal elements, then CreateSet must return 0
  IntegerSet* sBad = CreateSet(myarr, 3);
  int largearr[] = {1, 5, INT_MAX, INT_MIN, 1000000000, -123, 555, 0};
  IntegerSet* sLarge = CreateSet(largearr, 8);
  ck_assert_int_eq(IsInSet(sLarge, INT_MAX), 1);
  ck_assert_int_eq(IsInSet(sLarge, INT_MIN), 1);
  ck_assert_int_eq(IsInSet(sLarge, 1000000000), 1);
  ck_assert_int_eq(IsInSet(sLarge, -123), 1);
  ck_assert_int_eq(IsInSet(sLarge, 123), 0);
  ck_assert_int_eq(IsInSet(sLarge, -5), 0);

  DeleteSet(sLarge);  // set is destroyed
  largearr[1] = 5;
  sLarge = CreateSet(largearr, 8);  // same set as previously
  ck_assert_int_eq(IsInSet(sLarge, 5), 1);

  DeleteSet(sLarge);  // set is destroyed
  largearr[7] = 5;
  sLarge = CreateSet(largearr, 8);  // now it has equal elements

  DeleteSet(sLarge);  // set is destroyed
}
END_TEST

Suite* suite_create_matrix(void) {
  Suite* suite = suite_create("s21_matrix");
  // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
  TCase* tcase_core = tcase_create("matrix");

  // Добавление теста в группу тестов.
  tcase_add_test(tcase_core, test);

  // Добавление теста в тестовый набор.
  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  int failed_count;
  Suite* suite = suite_create_matrix();
  SRunner* suite_runner = srunner_create(suite);

  srunner_run_all(suite_runner, CK_NORMAL);
  failed_count =
      srunner_ntests_failed(suite_runner);  // запускаем все тестовые случаи
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}