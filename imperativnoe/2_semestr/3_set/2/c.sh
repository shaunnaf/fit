gcc -c zlib/*.c
gcc -c -DUSE_CRYPT -I./zlib -I./zlib/minizip zlib/minizip/unzip.c zlib/minizip/ioapi.c
gcc -c -DUSE_CRYPT -I./zlib -I./zlib/minizip test.c
gcc *.o -o checked_solution

// стадии компиляции, -L, различия в лвл,