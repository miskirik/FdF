SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)
NAME			= get_next_line.a
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all : ${NAME}


$(NAME) : ${OBJS}
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.c.o :
	@${CC} ${CFLAGS} -c $< -o $@

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o
