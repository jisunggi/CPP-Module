NAME = AccountLog
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
RM = rm
RMFLAGS = -f

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: all clean fclean re
