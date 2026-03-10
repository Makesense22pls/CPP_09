NAME = PmergeMe

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
			$(CXX) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all
