SERVER = gcc -o server server.c

CLIENT = gcc -o client client.c

RM = rm -rf client server
all:
	$(SERVER)
	$(CLIENT)
re :
	$(RM)
	$(SERVER)
	$(CLIENT)
clean :
	$(RM)