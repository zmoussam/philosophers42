# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 21:03:36 by zmoussam          #+#    #+#              #
#    Updated: 2022/09/13 20:36:24 by zmoussam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
BONUS_NAME = philo_bonus
SRC = ./mandatory/philosophers.c ./libft/ft_atoi.c ./libft/ft_isdigit.c\
	./mandatory/init_philo_and_mutex.c ./mandatory/join_philosophers.c\
	./mandatory/parssing.c  ./mandatory/routine.c ./mandatory/get_time.c\
	./mandatory/routine_func.c
			
BNS_SRC = ./philo_bonus/philo_bonus.c
OBJ = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS =  -Wall -Wextra -Werror

all: $(NAME)

	
%.o:%.c *.h
	@$(CC) -c  $(CFLAGS) $<
	
$(NAME): $(OBJ)  ./mandatory/philosophers.h ./libft/libft.h
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