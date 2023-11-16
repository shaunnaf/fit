CC=gcc
CFLAGS=-Wall -Werror -Werror -pedantic -std=c11

all: clean min_data binom names_and_ages simple fibonnaci factorial long_multiply

min_data:
	rm -rf min_data
	$(CC) $(CFLAGS) 1.min_data.c -g -o min_data
binom:
	rm -rf binom
	$(CC) $(CFLAGS) 2.binom.c -g -o binom
names_and_ages:
	rm -rf names_and_ages
	$(CC) $(CFLAGS) 3.names_and_ages.c -g -o names_and_ages
simple:
	rm -rf simple
	$(CC) $(CFLAGS) 4.simple.c -g -o simple
fibonnaci:
	rm -rf fibonnaci
	$(CC) $(CFLAGS) 5.fibonnaci.c -g -o fibonnaci
factorial:
	rm -rf factorial
	$(CC) $(CFLAGS) 6.factorial.c -g -o factorial
long_multiply:
	rm -rf long_multiply
	$(CC) $(CFLAGS) 7.long_multiply.c -g -o long_multiply


clean:
	rm -rf min_data binom names_and_ages simple fibonnaci factorial long_multiply *.o *.a *.out *.dSYM