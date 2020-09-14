# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labsorbi <labsorbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 19:43:11 by labsorbi          #+#    #+#              #
#    Updated: 2020/09/02 21:17:35 by labsorbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= bsq

MAIN				= ft_main.c

FLAGS 				= -Wall -Wextra -Werror

all:				${NAME}

${NAME}:			ft_main.o ft_read_map.o ft_check.o ft_error.o \
						ft_print_map.o ft_print_util.o ft_string.o
					@gcc ${FLAGS} -o ${NAME} \
						ft_main.o ft_read_map.o ft_check.o ft_error.o \
							ft_print_map.o ft_print_util.o ft_string.o

ft_main.o:			${MAIN} ft_map.h
					gcc ${FLAGS} -c ${MAIN}

ft_read_map.o:		ft_read_map.c ft_map.h
					gcc ${FLAGS} -c ft_read_map.c 

ft_check.o:			ft_check.c ft_map.h
					gcc ${FLAGS} -c ft_check.c

ft_error.o:			ft_error.c ft_map.h
					gcc ${FLAGS} -c ft_error.c

ft_print_map.o:		ft_print_map.c ft_map.h
					gcc ${FLAGS} -c ft_print_map.c

ft_print_util.o:	ft_print_util.c ft_map.h
					gcc ${FLAGS} -c ft_print_util.c

ft_string.o:		ft_string.c ft_map.h
					gcc -c ft_string.c

clean:
					@rm -f ft_main.o ft_read_map.o ft_check.o ft_error.o \
						ft_print_map.o ft_print_util.o ft_string.o \
							map6

fclean:				clean
					@rm -f ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
