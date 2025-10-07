DIR = include/headers
CC = gcc
CFLAGS = -Wall -Wextra -g
exe = script
LIB = $(wildcard lib*.a)

$(exe): script.c 
	$(CC) $(CFLAGS) $@.c -o $@ -I$(DIR) $(LIB)

.PHONY: clean

clean:
	rm $(exe)