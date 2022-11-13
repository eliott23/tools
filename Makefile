FLAGS=-Wall -Wextra -Werror
NAME=server\
client\
CSRC=helper.c\
client.c\
SSRC=helper.c\
server.c\

COBJ=$(CSRC:.c=.o)
SOBJ=$(SSRC:.c=.o)

all:$(NAME)

$(NAME):$(COBJ) $(SOBJ)

$(COBJ):$(CSRC)
	cc $(FLAGS) -o $@
$(CSRC):
	cc $(FLAGS) -c $@

$(SOBJ):$(SSRC)
	cc $(FLAGS) -o $@
$(SSRC):
	cc $(FLAGS) -c $@
clean:
clean:
	rm -rf $(COBJ) $(SOBJ)

re: clean all

fclean: clean
	rm -rf $(NAME)
	rm -rf $(COBJ) $(SOBJ)
