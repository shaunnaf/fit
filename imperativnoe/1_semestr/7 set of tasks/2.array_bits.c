#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long bitword;

void bitsetZero(bitword *arr, int num) {
  int size = (num + sizeof(bitword) * 8 - 1) / (sizeof(bitword) * 8);
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
}

int bitsetGet(const bitword *arr, int idx) {
  int wordIdx = idx / (sizeof(bitword) * 8);
  int bitIdx = idx % (sizeof(bitword) * 8);
  return (arr[wordIdx] >> bitIdx) & 1;
}

void bitsetSet(bitword *arr, int idx, int newval) {
  int wordIdx = idx / (sizeof(bitword) * 8);
  int bitIdx = idx % (sizeof(bitword) * 8);
  if (newval) {
    arr[wordIdx] |= ((bitword)1 << bitIdx);
  } else {
    arr[wordIdx] &= ~((bitword)1 << bitIdx);
  }
}

int bitsetAny(const bitword *arr, int left, int right) {
  int startWord = left / (sizeof(bitword) * 8);
  int endWord = (right + sizeof(bitword) * 8 - 1) / (sizeof(bitword) * 8);

  for (int i = startWord; i < endWord; i++) {
    if (arr[i] != 0) {
      return 1;  // some
    }
  }

  return 0;  // none
}

int main() {
  int N;
  scanf("%d", &N);

  bitword *arr = NULL;

  for (int i = 0; i < N; i++) {
    int t;
    scanf("%d", &t);

    if (t == 0) {
      int num;
      scanf("%d", &num);
      arr = (bitword *)malloc(
          ((num + sizeof(bitword) * 8 - 1) / (sizeof(bitword) * 8)) *
          sizeof(bitword));
      bitsetZero(arr, num);
    } else if (t == 1) {
      int idx;
      scanf("%d", &idx);
      printf("%d\n", bitsetGet(arr, idx));
    } else if (t == 2) {
      int idx, newval;
      scanf("%d %d", &idx, &newval);
      bitsetSet(arr, idx, newval);
    } else if (t == 3) {
      int left, right;
      scanf("%d %d", &left, &right);
      if (bitsetAny(arr, left, right)) {
        printf("some\n");
      } else {
        printf("none\n");
      }
    }
  }

  free(arr);
  return 0;
}
