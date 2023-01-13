mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
work_dir := $(dir $(mkfile_path))

flags := -std=c11 -Wall -Wextra -Wpedantic -Werror
NAME := way_home

all: clean $(NAME)

$(NAME): 
	clang $(flags) -I $(work_dir)inc                                    $(work_dir)src/*.c    -o $(work_dir)$(NAME)

uninstall:
	rm -rf $(work_dir)$(NAME) 

clean:
	rm -rf $(work_dir)$(NAME) 

reinstall:
	make uninstall
	make all
