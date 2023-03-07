# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samajat <samajat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 22:05:55 by samajat           #+#    #+#              #
#    Updated: 2023/03/07 15:30:13 by samajat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STL_NAME = stdContainer
STD_NAME = ftContainer
MAIN_NAME = mainContainer

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
MAIN_TEST = test/main

STD_OBJ = $(STD_TEST:=.o)
STL_OBJ = $(STL_TEST:=.o)
MAIN_OBJ = $(MAIN_TEST:=.o)

HEADERS = $(addprefix ./includes/containers/,  $(SRC_INC))

	
all : $(STL_NAME) $(STD_NAME) $(MAIN_NAME)

$(STL_NAME) : $(STL_OBJ) 
	@$(CC) $(FLAGS)  $(STL_OBJ) -o $(STL_NAME) 
	
$(STD_NAME) : $(STD_OBJ) 
	@$(CC) $(FLAGS)  $(STD_OBJ) -o $(STD_NAME) 
$(MAIN_NAME) : $(MAIN_OBJ) 
	@$(CC) $(FLAGS)  $(MAIN_OBJ) -o $(MAIN_NAME) 


%.o:%.cpp $(HEADERS) 
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@$(RM) $(STD_OBJ) $(STL_OBJ) $(MAIN_OBJ)

fclean : clean
	@$(RM) $(STL_NAME) $(STD_NAME) $(MAIN_NAME)

re : fclean all

bonus : all
