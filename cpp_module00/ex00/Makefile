NAME = megaphone 
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.c=.o)
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

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: all clean fclean re
