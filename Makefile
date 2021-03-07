# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 16:32:36 by vvaucoul          #+#    #+#              #
#    Updated: 2021/03/03 20:30:24 by vvaucoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := ft_container
NAME_B   := ft_container_bonus
SRCS     := tests/main.cpp \
			tests/testsList.cpp \
			tests/testsMap.cpp \
			tests/testsQueue.cpp \
			tests/testsStack.cpp \
			tests/testsVector.cpp \
			tests/testsBonus/testsDeque.cpp \
			tests/testsBonus/testsMultimap.cpp \
			tests/testsBonus/testsMultiset.cpp \
			tests/testsBonus/testsSet.cpp


OBJS     := $(SRCS:.cpp=.o)
CXX      := clang++
CXXFLAGS :=	-I./srcs/utils/ \
			-I./srcs/list/ \
			-I./srcs/map/ \
			-I./srcs/vector/ \
			-I./srcs/queue/ \
			-I./srcs/stack/ \
			-I./srcsBonus/ \
			-I./srcsBonus/set/ \
			-I./srcsBonus/multiset/ \
			-I./srcsBonus/multimap/ \
			-I./srcsBonus/deque/ \
			-g3 \
			-std=c++98 -Wall -Werror -Wextra -g3

CXXFLAGS_BONUS := $(CXXFLAGS) -I./srcsBonus/

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_BONUS) -o $@ -c $<

bonus:	fclean $(NAME_B)

$(NAME_B): $(OBJS)
	@$(CXX) $(OBJS) -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) $(NAME_B)

re:     fclean all

.PHONY: all clean fclean format re
