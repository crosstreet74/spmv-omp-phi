cc = gcc

# ping pong example using MPI_Send and MPI_Recv
sources = mmio.c sparse.c dense.c util.c reorder.c main.c
objects = $(addsuffix .o, $(basename $(sources)))

flags = -g -std=gnu11 -fopenmp -DDEBUG=1 -Iinclude

target = hb_load

all: $(target) 

$(target) : $(objects)
	$(cc) $(flags) -o $(target) $(objects)

%.o : %.c
	$(cc) -c $(flags) $< -o $@

clean:
	rm -rf $(target) $(objects) 
