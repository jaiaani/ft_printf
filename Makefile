# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaiane <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 23:25:39 by jaiane            #+#    #+#              #
#    Updated: 2024/12/05 01:36:06 by jaiane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc

CCFLAGS := -Wall -Wextra -Werror

RM := rm -f

AR := ar rcs

SRCS = helpers/print_numbers.c helpers/print_ascii.c helpers/print_pointer.c ft_printf.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CCFLAGS) -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
