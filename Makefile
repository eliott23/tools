FLAGS=-Wall -Wextra -Werror
NAME=server\
client
B_NAME=checker
SRC=helper.c\
server.c\
client.c\

OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	cc $(FLAGS) -o $@ $(OBJ)

$(OBJ) : $(SRC)
	cc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ) $(OBJ_B)

re: clean all
fclean: clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
