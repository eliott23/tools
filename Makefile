FLAGS=-Wall -Wextra -Werror
Client=client
Server=Server
NAME=$(Server) $(Client)
CSRC=helper.c\
client.c\
SSRC=helper.c\
server.c\

COBJ=$(CSRC:.c=.o)
SOBJ=$(SSRC:.c=.o)

all:$(NAME)

$(Client):$(COBJ)
	cc $(FLAGS) -o $@ $(COBJ) 

$(Server):$(SOBJ)
	cc $(FLAGS) -o $@ $^

$(COBJ) : $(CSRC)
	cc $(FLAGS) -c $(CSRC)

$(SOBJ) : $(SSRC)
	cc $(FLAGS) -c $(SSRC)

clean:
	rm -rf $(COBJ) $(SOBJ)

re: clean all

fclean: clean
	rm -rf $(NAME)
	rm -rf $(COBJ) $(SOBJ)
