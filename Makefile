FLAGS=-Wall -Wextra -Werror
NAME=client\
CSRC=helper.c\
client.c\
SSRC=helper.c\
server.c\

COBJ=$(CSRC:.c=.o)
SOBJ=$(SSRC:.c=.o)

all:client

client:$(COBJ)
	cc $(FLAGS) -o client $(COBJ)

$(COBJ):$(CSRC)
	cc $(FLAGS) -c $^

