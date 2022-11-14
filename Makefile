FLAGS=-Wall -Wextra -Werror
NAME=server\

NAME2=client\

CSRC=helper.c\
client.c\

SSRC=server.c\

HSRC=helper.c\

HOBJ=helper.o\

COBJ=client.o\

SOBJ=server.o\

all:$(NAME) $(NAME2)

$(NAME):$(SOBJ) $(HOBJ)
	cc $(FLAGS) -o $@ $^

$(SOBJ):$(SSRC)
	cc $(FLAGS) -c $^

$(HOBJ):$(HSRC)
	cc $(FLAGS) -c $^

$(NAME2):$(COBJ) $(HOBJ)
	cc $(FLAGS) -o $@ $^

$(COBJ):$(CSRC)
	cc $(FLAGS) -c $^

clean:
	rm -rf $(HOBJ) $(COBJ) $(SOBJ)

fclean:clean
	rm -rf $(NAME) $(NAME2)

re:fclean all
