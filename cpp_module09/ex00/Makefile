NAME = btc
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
RMFLAGS = -f

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CLIB) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: all clean fclean re