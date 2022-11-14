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
	cc $(FLAGS) -o server $^

$(SOBJ):$(SSRC)
	cc $(FLAGS) -c $^

$(HOBJ):$(HSRC)
	cc $(FLAGS) -c $^

$(NAME2):$(COBJ) $(HOBJ)
	cc $(FLAGS) -o client $^

$(COBJ):$(CSRC)
	cc $(FLAGS) -c $^
