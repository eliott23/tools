FLAGS=-Wall -Wextra -Werror
Client=client
Server=Server
CSRC=helper.c\
client.c\
SSRC=helper.c\
server.c\

COBJ=$(CSRC:.c=.o)
SOBJ=$(SSRC:.c=.o)

all:$(NAME)

$(NAME):$(COBJ) $(SOBJ)

$(COBJ):$(CSRC)
	cc $(FLAGS) -o client client.o helper.o

$(CSRC):
	cc $(FLAGS) -c helper.c client.c

$(SOBJ):$(SSRC)
	cc $(FLAGS) -o server helper.o server.o

$(SSRC):
	cc $(FLAGS) -c helper.c server.c

clean:
	rm -rf $(COBJ) $(SOBJ)

re: clean all

fclean: clean
	rm -rf $(NAME)
	rm -rf $(COBJ) $(SOBJ)
