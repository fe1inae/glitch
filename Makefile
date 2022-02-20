.POSIX:
.PHONY: all clean

CC     = gcc
CFLAGS = -Wall -Werror -Os

all: glitch

clean:; rm -f glitch
