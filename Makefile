# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:05:55 by samajat           #+#    #+#              #
#    Updated: 2023/03/07 10:25:41 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STL_NAME = stdContainer
STD_NAME = ftContainer

CC = c++

RM =  rm -rf

SRV_V = vector.hpp
SRV_M = map.hpp
SRV_ST = stack.hpp
SRV_SE = set.hpp

SRC_PATH = $(SRV_V) $(SRV_M) $(SRV_ST) $(SRV_SE) 

CFLAGS =  -Wall -Wextra -Werror -std=c++98

STD_TEST = test/ftContainers.cpp
STL_TEST = test/stdContainers.cpp

STD_OBJ = $(STD_TEST:=.o)
STL_OBJ = $(STL_TEST:=.o)

HEADERS = $(addprefix ./includes/containers/,  $(SRC_PATH))

all : $(STL_NAME) $(STD_NAME)

$(STL_NAME) : $(STL_OBJ) 
	@$(CC) $(FLAGS)  $(STL_OBJ) -o $(STL_NAME) 
	
$(STD_NAME) : $(STD_OBJ) 
	@$(CC) $(FLAGS)  $(STD_OBJ) -o $(STD_NAME) 

	
clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

bonus : all
