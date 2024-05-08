gcc -Wall -Wextra -Werror -c func.c -o integerset.o 
gcc -shared integerset.o -o integerset.so 