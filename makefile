CC= cc 

CFLAGS= -Wall -Wextra -Werror

NAME= push_swap
CHECK= checker

FILES= parse_util0.c  parse_util1.c parse_util2.c  parse_util3.c   algo_util.c\
		rules0.c rules1.c algo_util0.c algo_util1.c  algo_util2.c get_next_line_utils.c\

CHECKFILES= checker_0.c  checker_main.c parse_util0.c  parse_util1.c parse_util2.c  parse_util3.c \
				rules0.c rules1.c get_next_line.c get_next_line_utils.c \

OBJ= ${FILES:.c=.o}
OBJ_CHECK= ${CHECKFILES:.c=.o}
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(CHECK)

$(CHECK): $(OBJ_CHECK)
	$(CC) $(CFLAGS) $(OBJ_CHECK) -o $(CHECK)

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_CHECK)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(CHECK)

re : fclean all

.PHONY: clean