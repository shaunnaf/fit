CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
OBJDIR = obj
SRC = $(wildcard *.c)

OBJ = $(patsubst %.c,%.o,$(SRC))

all: clean myblas.a

myblas.a: $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	-rm -rf *.o
	-rm -rf *.a