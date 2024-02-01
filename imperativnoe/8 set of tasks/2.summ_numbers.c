#include <stdint.h>
#include <stdio.h>

uint32_t reverseBytes(uint32_t num) {
  return ((num & 0xFF) << 24) | (((num >> 8) & 0xFF) << 16) |
         (((num >> 16) & 0xFF) << 8) | ((num >> 24) & 0xFF);
}

0x00 00 00 01 0x00 00 27 10 0x10 27 00 00 0x01 00 00 00

    0x00 00 01 00 0x00 01 00 00

    int
    main() {
  FILE* inputFile = fopen("input.txt", "rb");
  FILE* outputFile = fopen("output.txt", "wb");

  int32_t n;
  int32_t sum = 0;
  fread(&n, sizeof(int32_t), 1, inputFile);
  if (n <= 10000 && n > 0) {
    for (int32_t i = 0; i < n; i++) {
      int32_t num;
      fread(&num, sizeof(int32_t), 1, inputFile);
      sum += num;
    }

  } else {
    n = reverseBytes(n);

    for (uint32_t i = 0; i < n; i++) {
      int32_t num;
      fread(&num, sizeof(int32_t), 1, inputFile);
      num = reverseBytes(num);
      sum += num;
    }
    sum = reverseBytes(sum);
  }
  fwrite(&sum, sizeof(int32_t), 1, outputFile);

  fclose(inputFile);
  fclose(outputFile);

  return 0;
}
