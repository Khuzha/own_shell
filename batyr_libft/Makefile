# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomitil <bdomitil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:40:08 by bdomitil          #+#    #+#              #
#    Updated: 2021/02/28 21:27:04 by bdomitil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

files.c = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c  ft_islower_bonus.c  \
                    ft_char_index_bonus.c ft_isupper_bonus.c ft_space_bonus.c ft_strcmp_bonus.c  \
					get_next_line.c get_next_line_utils.c ft_isempty_str.c ft_atoi_long.c ft_all_numeric.c  \
					ft_strcpy.c
					

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c	ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

bonus.o = $(BONUS:.c=.o)


files.o = $(files.c:.c=.o)

NAME = libft.a


all :	$(NAME)

$(NAME) : $(files.o)
		@ar -rcs libft.a $(files.o)
		@echo "\033[7m lib is compiled!\033[0m"

bonus :  $(files.o) $(bonus.o)
		@ar -rcs $(NAME) $(files.o) $(bonus.o)
		@echo "\033[7m lib is compiled!\033[0m"

%.o : %.c 
		@gcc -g -Wall -Wextra -Werror  -c  $<  -o $@
		@echo "\033[36m$<\033[0m \033[35m is compiled!\033[0m"

clean :  
		@rm -f *.o
		@echo "\033[7mclean is done!\033[0m"

fclean :
		@rm  -f *.o $(NAME)
		@echo "\033[7mfclean is done!\033[0m"

re	:  fclean libft.a	


.PHONY : all clean  fclean bonus
