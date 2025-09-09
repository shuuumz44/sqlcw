headers := $(wildcard *.h) $(wildcard *.c)
INC_DIR := -I./headers
script: script.c headers
	gcc -o script.exe script.c libsqlite3.a $(INC_DIR)