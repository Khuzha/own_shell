NAME = minishell.out
SRCS = engine/main.c

SRCOBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCOBJS) headers/*.h
		make -C libft
		ar -rcs $(NAME) $(SRCOBJS) libft/*.o
		gcc $(NAME) -ltermcap

all: $(NAME)

clean : 
				rm -rf $(SRCOBJS) 
				make -C libft/ clean

fclean : clean
				make -C libft/ fclean
				rm -rf $(NAME)

re :  fclean all 

d:
		gcc -Wall -Wextra -Werror -g printf.c atoi.c print_d.c

t: fclean all
		gcc -Wall -Wextra -Werror -g main.c libftprintf.a

f: fclean all
		gcc -Wall -Wextra -Werror -g -fsanitize=address main.c libftprintf.a

w: fclean all
		gcc -g main.c libftprintf.a

dbg: fclean
		gcc -g main.c $(SRCS) libft/ft_itoa.c libft/ft_atoi.c libft/ft_strlen.c libft/ft_substr.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_strdup.c