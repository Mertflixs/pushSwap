NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c				\
			checkandcreate.c	\
			ft_atoi.c			\
			ft_sort.c			\
			ft_split.c			\
			is_digit.c			\
			utils.c				\
			utils2.c			\

OBJS=	$(SRCS:.c=.o)
PRIN =	./ft_printf/ft_printf.a
all:	$(PRIN)  ${NAME}
$(PRIN):
	@make -C ./ft_printf


$(NAME):	$(OBJS) $(PRIN)
	@$(CC) ${CFLAGS} $(OBJS) -o $(NAME) $(PRIN)

%.o:	%.c
	@echo $(R)Complining: [$<]
	@${CC} -c $^ -o $@ -Wall -Werror -Wextra

clean:
	@rm -rf ${OBJS}
	@make clean -C ft_printf/

fclean: clean
	@rm -rf ${NAME}
	@make fclean -C ft_printf/

re: fclean all

.PHONY: fclean re all clean