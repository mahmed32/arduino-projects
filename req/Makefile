flags = -Werror
all : server client
server : server.o utility.o
	gcc $(flags) server.o utility.o -o server 
server.o: server.c
	gcc $(flags) -c server.c
utility.o: utility.c
	gcc $(flags) -c utility.c
client : client.o utility.o
	gcc $(flags) client.o utility.o -o client
client.o: client.c
	gcc $(flags) -c client.c
.PHONY clean:
clean:
	rm server.o utility.o server client client.o
