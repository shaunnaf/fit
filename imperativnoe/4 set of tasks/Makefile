CC=gcc
CFLAGS=-Wall -Werror -Werror -pedantic -std=c11

all: clean time reverse_string connect_string how_much_bukow div_on_words read_time gistogramma 

time:
	rm -rf time
	$(CC) $(CFLAGS) 1.time.c -g -o time
reverse_string:
	rm -rf reverse_string
	$(CC) $(CFLAGS) 2.reverse_string.c -g -o reverse_string
connect_string:
	rm -rf connect_string
	$(CC) $(CFLAGS) 3.connect_string.c -g -o connect_string
how_much_bukow:
	rm -rf how_much_bukow
	$(CC) $(CFLAGS) 4.how_much_bukow.c -g -o how_much_bukow
div_on_words:
	rm -rf div_on_words
	$(CC) $(CFLAGS) 5.div_on_words.c -g -o div_on_words
read_time:
	rm -rf read_time
	$(CC) $(CFLAGS) 6.read_time.c -g -o read_time
gistogramma:
	rm -rf gistogramma
	$(CC) $(CFLAGS) 7.gistogramma.c -g -o gistogramma

clean:
	rm -rf time reverse_string connect_string how_much_bukow div_on_words min_ read_time gistogramma  *.o *.a *.out *.dSYM