# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:03:36 by zmoussam          #+#    #+#              #
#    Updated: 2022/09/13 21:33:25 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philos
BONUS_NAME = philos_bonus
SRC = ./philo/philosophers.c ./libft/ft_atoi.c ./libft/ft_isdigit.c\
	./philo/init_philo_and_mutex.c ./philo/join_philosophers.c\
	./philo/parssing.c  ./philo/routine.c ./philo/get_time.c\
	./philo/routine_func.c
			
BNS_SRC = ./philo_bonus/philo_bonus.c
OBJ = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror

all: $(NAME)

	
%.o:%.c *.h
	@$(CC) -c  $(CFLAGS) $<
	
$(NAME): $(OBJ)  ./philo/philosophers.h ./libft/libft.h
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME)
 
$(BONUS_NAME) : $(BOBJ)  ./libft/libft.h
	@$(CC) $(CFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"
	
	
clean:
	@$(RM) $(OBJ) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "Clear"

re: fclean all