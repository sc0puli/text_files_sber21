CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
.PHONY: all clean rebuild cipher

all: cipher

clean: rm -f *.o ../build/Quest_*

rebuild: clean all

cipher: 
	$(CC) $(CFLAGS) -o ../build/cipher cipher.c
