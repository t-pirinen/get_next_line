




NAME = get_next_line.a

C = cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=10

SRC = get_next_line.c get_next_line_utils.c test.c

OBJ = $(SRC:.c=.o)



all:
		@$(C) $(SRC)
		@./a.out test.txt

clean:
		rm -rf a.out

fclean: clean
		rm -rf *.a
		rm -rf *.o

.PHONY: all test clean fclean