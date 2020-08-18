all: op_client op_server

op_client: op_client.c err_handle.c err_handle.h
	gcc -o op_client op_client.c err_handle.c 

op_server: op_server.c err_handle.c err_handle.h
	gcc -o op_server op_server.c err_handle.c

clean:
	rm op_client op_server
