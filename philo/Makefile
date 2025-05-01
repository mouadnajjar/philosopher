# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monajjar <monajjar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 19:53:04 by monajjar          #+#    #+#              #
#    Updated: 2025/04/23 10:49:51 by monajjar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= philo

SRCS := philo.c helpers.c parsing.c philos_setup.c  routine_config.c routins.c simulation_detect.c short_funcs.c short_funcs2.c \

OBJS := $(SRCS:.c=.o)

HEADER := philo.h

CFLAGS := -Wall -Wextra -Werror

CC := cc

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re: fclean all

.SECONDARY: $(OBJS)

.PHONY: all clean fclean re