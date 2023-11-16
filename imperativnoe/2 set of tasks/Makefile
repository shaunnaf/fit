CC=gcc
CFLAGS=-Wall -Werror -Werror -pedantic -std=c11

all: clean simple_to_n day_of_the_week count_the_signs rectangle words bits_and_baits arithmetic_progressions data

simple_to_n:
	rm -rf simple_to_n
	$(CC) $(CFLAGS) 1.simple_to_n.c -g -o simple_to_n
day_of_the_week:
	rm -rf day_of_the_week
	$(CC) $(CFLAGS) 2.day_of_the_week.c -g -o day_of_the_week
count_the_signs:
	rm -rf count_the_signs
	$(CC) $(CFLAGS) 3.count_the_signs.c -g -o count_the_signs
rectangle:
	rm -rf rectangle
	$(CC) $(CFLAGS) 4.rectangle.c -g -o rectangle
words:
	rm -rf words
	$(CC) $(CFLAGS) 5.words.c -g -o words
bits_and_baits:
	rm -rf bits_and_baits
	$(CC) $(CFLAGS) 6.bits_and_baits.c -g -o bits_and_baits
arithmetic_progressions:
	rm -rf arithmetic_progressions
	$(CC) $(CFLAGS) 7.arithmetic_progressions.c -g -o arithmetic_progressions
data:
	rm -rf data
	$(CC) $(CFLAGS) 8.data.c -g -o data

clean:
	rm -rf simple_to_n day_of_the_week count_the_signs rectangle words min_data bits_and_baits arithmetic_progressions data *.o *.a *.out *.dSYM