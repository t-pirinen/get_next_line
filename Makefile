






C = cc -Wall -Wextra -Werror -D BUFFER_SIZE=n

SRC = get_next_line.c get_next_line_utils.c maintest.c

OBJ = $(SRC.c=.o)

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

all:
		@$(C) $(SRC)
		@./a.out
		@rm -rf a.out

clean:
		rm -rf a.out

fclean: clean
		

.PHONY: all test clean fclean