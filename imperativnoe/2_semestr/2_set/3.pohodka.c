#include <stdint.h>
#include <stdio.h>

#if UINTPTR_MAX == 0xffffffff
int BIT = 32;
#elif UINTPTR_MAX == 0xffffffffffffffff
int BIT = 64;
#endif

#ifdef NDEBUG
int ASSERT = 0;
#else
int ASSERT = 1;
#endif

#if defined(__GNUC__) && !defined(__llvm__) && !defined(__INTEL_COMPILER)
int COMPILER = 1;
#elif defined(__TINYC__)
int COMPILER = 2;
#elif defined(__clang_version__)
int COMPILER = 3;
#endif

int main() {
  printf("Compiler: ");
  if (COMPILER == 1)
    printf("GCC\n");
  else if (COMPILER == 2)
    printf("TCC\n");
  else
    printf("clang\n");
  printf("Bitness: %d\n", BIT);
  if (ASSERT)
    printf("Asserts: enabled");
  else
    printf("Asserts: disabled");
  return 0;
}