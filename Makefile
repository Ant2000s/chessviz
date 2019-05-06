all: bin/main

bin/main: build/main.o build/board_print_plain.o
	gcc -Wall -Werror build/main.o build/board_print_plain.o -o bin/main

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/board_print_plain.o: src/board_print_plain.c
	gcc -Wall -Werror -c src/board_print_plain.c -o build/board_print_plain.o

.PHONY:clean

clean:
	rm -rf build/*.o
