CC=gcc
CFLAGS=-Wall -Werror -Werror -pedantic -std=c11

all: clean print_list simply_linked_list

print_list:
	rm -rf print_list
	$(CC) $(CFLAGS) 1.print_list.c -o print_list

simply_linked_list:
	rm -rf simply_linked_list
	$(CC) $(CFLAGS) 2.simply_linked_list.c -o simply_linked_list

clean:
	rm -rf print_list simply_linked_list *.o *.a *.out *.dSYM