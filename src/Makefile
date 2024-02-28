CC=gcc
CFLAGS=-Wall -Werror -Wextra

all: clean roman_to_arabic

roman_to_arabic: roman_to_arabic.o
	$(CC) $(CFLAGS) roman_to_arabic.o -o roman_to_arabic

roman_to_arabic.o:
	$(CC) $(CFLAGS) -c roman_to_arabic.c -o roman_to_arabic.o

clean:
	rm -rf *.o