all: CALC

CALC: makedir
	cp ./inc/*.h ./obj/
	cp ./src/*.c ./obj/
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic ./obj/*.c -o calc
	rm -rf obj

reinstall: uninstall CALC

makedir:
	mkdir obj

uninstall:
	rm -rf obj
	rm calc

clean:
	rm -f obj/*.c
	rm -f obj/*.h



