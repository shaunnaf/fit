#include <stdio.h>

int main() {
  FILE *mf;
  int number_a, number_b;
  mf = fopen("input.txt", "rb");
  if (mf != NULL) {
    fread(&number_a, sizeof(int), 1, mf);
    fread(&number_b, sizeof(int), 1, mf);
    fclose(mf);
    mf = fopen("output.txt", "wb");
    if (mf != NULL) {
      long long rounded_result =
          ((long long)number_a + (long long)number_b) >> 1;
      fwrite(&rounded_result, sizeof(int), 1, mf);
      fclose(mf);
    }
  }
  return 0;
}
