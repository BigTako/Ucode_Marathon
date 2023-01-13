all: part_of_the_matrix

part_of_the_matrix:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -Iinc -o mx_cat src/*.c

clean:
	rm -rf mx_cat

uninstall:
	rm -rf mx_cat

reinstall:
	make uninstall
	make
