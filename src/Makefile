all: op_client op_server

# bin file suffix
BINEXT = 
# so file suffix 
SOEXT ?=
# complier
CC ?= gcc
# complier parameter
CFALGS ?= 
# prefix
PREFIX ?=
# library
LIBDIR ?=
# header file 
INCLUDEDIR = 

objects = err_handle.o

err_handle.o: err_handle.c err_handle.h
	$(cc) -c err_handle.c

op_client: op_client.c $(objects)
	$(cc) -o op_client op_client.c $(objects) 

op_server: op_server.c $(objects)
	$(cc) -o op_server op_server.c $(objects)

# .PHONY explain "clean" is a false target 
.PHONY: clean

clean:
	rm op_client op_server

