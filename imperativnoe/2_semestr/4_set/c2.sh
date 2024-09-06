gcc -Wall -Wextra -Werror -c integerset.c -o integerset.o
gcc -shared integerset.o -o integerset.so