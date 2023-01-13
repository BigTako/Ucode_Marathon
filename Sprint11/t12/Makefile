all: part_of_the_matrix

part_of_the_matrix:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o playlist src/*.c

clean:
	rm -rf mx_wc

uninstall:
	rm -rf mx_wc

reinstall:
	make uninstall
	make
