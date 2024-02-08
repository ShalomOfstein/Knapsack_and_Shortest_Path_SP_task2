CC = gcc
AR = ar
FLAG = -Wall -g -fPIC


#compile and link all the files
all: my_graph my_Knapsack



#compile the different mains
my_graph: my_graph.o libmy_mat.a
	$(CC) $(FLAG) -o my_graph my_graph.o libmy_mat.a 

my_Knapsack: my_Knapsack.o
	$(CC) $(FLAG) -o my_Knapsack my_Knapsack.o

#make the libraries:
libmy_mat.a: my_mat.o
	$(AR) rcu libmy_mat.a my_mat.o
	ranlib $@


#make the object files
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAG) -c my_graph.c -o my_graph.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAG) -c my_mat.c -o my_mat.o 

my_Knapsack.o: my_Knapsack.c
	$(CC) $(FLAG) -c my_Knapsack.c -o my_Knapsack.o


#to ensure that there isnt a "clean"/"all" file in the directory
.PHONY: clean all

#clean all the compiled files and leave the .txt/ .c / .h files
clean:
	rm -f *.o *.a *.so my_graph