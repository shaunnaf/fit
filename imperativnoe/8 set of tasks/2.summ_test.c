#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union num {
  int integer;
  unsigned char bytes[4];
} num;

int module(int value) {
  if (value >= 0) {
    return value;
  } else {
    return -value;
  }
}

int main() {
  int errcode = 0;
  FILE *fi = fopen("input.txt", "rb"), *fo = fopen("output.txt", "wb");
  if (fi == NULL || fo == NULL) {
    errcode = 1;
    goto error_handler;
  }
  num num, *number = &num, summa, *sum = &summa, n, *N = &n;
  char change;
  summa.integer = 0;
  if (fread(N, sizeof(int), 1, fi) != 1) {
    errcode = 2;
    goto error_handler;
  }
  if (module(n.integer) <= 10000) {
    for (int i = 0; i < n.integer; i++) {
      if (fread(number, sizeof(int), 1, fi) != 1) {
        errcode = 3;
        goto error_handler;
      }
      summa.integer += num.integer;
    }
    fwrite(sum, sizeof(int), 1, fo);
  } else {
    change = N->bytes[0];
    N->bytes[0] = N->bytes[3];
    N->bytes[3] = change;
    change = N->bytes[1];
    N->bytes[1] = N->bytes[2];
    N->bytes[2] = change;
    for (int i = 0; i < n.integer; i++) {
      if (fread(number, sizeof(int), 1, fi) != 1) {
        errcode = 3;
        goto error_handler;
      }
      change = number->bytes[0];
      number->bytes[0] = number->bytes[3];
      number->bytes[3] = change;
      change = number->bytes[1];
      number->bytes[1] = number->bytes[2];
      number->bytes[2] = change;
      summa.integer += num.integer;
    }
    change = sum->bytes[0];
    sum->bytes[0] = sum->bytes[3];
    sum->bytes[3] = change;
    change = sum->bytes[1];
    sum->bytes[1] = sum->bytes[2];
    sum->bytes[2] = change;
    fwrite(sum, sizeof(int), 1, fo);
  }

error_handler:
  fclose(fi);
  fclose(fo);
  return errcode;
}
