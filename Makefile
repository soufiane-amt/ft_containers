# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:05:55 by samajat           #+#    #+#              #
#    Updated: 2023/03/07 10:39:28 by samajat          ###   ########.fr        #
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

SRC_INC = $(SRV_V) $(SRV_M) $(SRV_ST) $(SRV_SE) 

CFLAGS =  -Wall -Wextra -Werror -std=c++98

STD_TEST = test/ftContainers
STL_TEST = test/stdContainers

STD_OBJ = $(STD_TEST:=.o)
STL_OBJ = $(STL_TEST:=.o)

HEADERS = $(addprefix ./includes/containers/,  $(SRC_INC))

	
all : $(STL_NAME) $(STD_NAME)

$(STL_NAME) : $(STL_OBJ) 
	@$(CC) $(FLAGS)  $(STL_OBJ) -o $(STL_NAME) 
	
$(STD_NAME) : $(STD_OBJ) 
	@$(CC) $(FLAGS)  $(STD_OBJ) -o $(STD_NAME) 


%.o::%.cpp $(HEADERS) 
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@$(RM) $(STD_OBJ) $(STL_OBJ)

fclean : clean
	@$(RM) $(STL_NAME) $(STD_NAME)

re : fclean all

bonus : all
