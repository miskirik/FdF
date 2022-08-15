SRCS			= $(wildcard *.c)
OBJS			= $(SRCS:.c=.o)

NAME			= fdf
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

LIB				= ./libft/libft.a
MINILIB 		= ./minilibx/libmlx.a
PRINT			=./ft_printf/libftprintf.a
GNL				=./get_next_line/get_next_line.a

INC_FT			= ./libft
INC_GN			= ./get_next_line
INC_PR			= ./ft_printf
INC_MX			= ./minilibx
LIB_PRINT		= ./ft_printf/libftprintf.a

all : $(MINILIB) $(LIB) $(PRINT) $(GNL) ${NAME}

$(MINILIB):
	@echo "milibx compilation started"
	@make -C ./minilibx
	@echo "compilation success"

$(LIB):
	@make -C ./libft
	@echo "\x1b[33mlibft compilation success\x1b[0m"
$(PRINT):
	@make -C ./ft_printf
	@echo "\x1b[33mprintf compilation success\x1b[0m"
$(GNL):
	@make -C ./get_next_line
	@echo "\x1b[33mget_next_line compilation success\x1b[0m"
$(NAME) : ${OBJS}
	@$(CC) $(OBJS) -framework OpenGL -framework AppKit -o $(NAME) $(LIB) $(MINILIB) $(PRINT) $(GNL)
	@echo "\x1b[33msrc compilation success\x1b[0m"
.c.o :
	@${CC} ${CFLAGS} -c $< -o $@ -I$(INC_PR) -I$(INC_GN) -I$(INC_FT) -I$(INC_MX)
clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

ffclean: fclean
	@make fclean -C ./libft
	@make fclean -C ./ft_printf
	@make fclean -C ./get_next_line
	@make clean -C ./minilibx
	@echo "Clean success"

norm :
	@norminette draw.c errors.c fdf.h main.c read_map.c utils.c utils2.c

re : fclean all

.PHONY: all clean fclean re .c.o
