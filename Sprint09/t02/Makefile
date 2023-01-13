all: MINILIBMX clean
reinstall: uninstall MINILIBMX
MINILIBMX: 
	mkdir obj; 
	cp inc/functions.h obj/functions.h;
	cp src/mx_atoi.c obj/mx_atoi.c;
	cp src/mx_isspace.c obj/mx_isspace.c;
	cp src/mx_isdigit.c obj/mx_isdigit.c;
	cp src/mx_printchar.c obj/mx_printchar.c;
	cp src/mx_printint.c obj/mx_printint.c;
	cp src/mx_printstr.c obj/mx_printstr.c;
	cp src/mx_strcmp.c obj/mx_strcmp.c; 
	cp src/mx_strcpy.c obj/mx_strcpy.c; 
	cp src/mx_strlen.c obj/mx_strlen.c; 
	clang -c -std=c11 -Wall -Wextra -Werror -Wpedantic obj/mx_atoi.c obj/mx_isspace.c obj/mx_isdigit.c obj/mx_printchar.c obj/mx_printint.c obj/mx_printstr.c obj/mx_strcmp.c obj/mx_strcpy.c obj/mx_strlen.c; \
	ar -crc minilibmx.a mx_atoi.o mx_isdigit.o mx_isspace.o mx_printchar.o mx_printint.o mx_printstr.o mx_strcmp.o mx_strcpy.o mx_strlen.o;

uninstall: 
	rm -rf minilibmx.a;
	rm -rf obj	
clean: 
	rm -r mx_atoi.o mx_isdigit.o mx_isspace.o mx_printchar.o mx_printint.o mx_printstr.o mx_strcmp.o mx_strcpy.o mx_strlen.o;
	rm -rf obj
	

