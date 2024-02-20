CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
OBJDIR = obj
TESTDIR = tests


SRC = $(wildcard *.c)
SRC2 = $(wildcard $(TESTDIR)/*.c)
HEAD = $(wildcard *.h)
OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))


all: clean module

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(HEAD) | $(OBJDIR)
	$(CC) -c $(CFLAGS) $< -o $@

module: $(OBJDIR) $(SRC) $(OBJ) $(HEAD)
	$(CC) $(OBJDIR)/main.o $(OBJDIR)/modular.o -o app

test: clean module
	$(CC) $(CFLAGS) $(SRC2) -lcheck -o test

clean:
	-rm -rf *.o
	-rm -rf ./obj
	-rm -rf app
	-rm -rf *.out

.PHONY: all clean