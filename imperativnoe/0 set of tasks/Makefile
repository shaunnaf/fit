CC=gcc
CFLAGS=-Wall -Werror -Werror -pedantic -std=c11

all: clean summ_of_two_numbers operations_on_two_numbers

summ_of_two_numbers:
	rm -rf summ_of_two_numbers
	$(CC) $(CFLAGS) 1.summ_of_two_numbers.c -o summ_of_two_numbers
operations_on_two_numbers:
	rm -rf operations_on_two_numbers
	$(CC) $(CFLAGS) 2.operations_on_two_numbers.c -o operations_on_two_numbers

clean:
	rm -rf summ_of_two_numbers operations_on_two_numbers *.o *.a *.out *.dSYM