# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhyeop <jinhyeop@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 15:17:44 by jinhyeop          #+#    #+#              #
#    Updated: 2023/11/28 13:12:08 by jinhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = ex00

SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o:%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@rm -f $(OBJS)
	@echo "All object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable file removed"

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
