CC = gcc
FLAGS = -g -Wall

all : my_graph my_Knapsack



.PHONY : all clean
my_graph : my_graph.o my_mat.o
	$(CC) $(FLAGS) my_graph.o my_mat.o -o my_graph

my_graph.o : my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c

my_mat.o : my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c


my_Knapsack : my_Knapsack.o
	$(CC) $(FLAGS) my_Knapsack.o -o my_Knapsack

my_Knapsack.o : my_Knapsack.c
	$(CC) $(FLAGS) -c my_Knapsack.c -o my_Knapsack.o

clean : 
	rm my_graph my_Knapsack *.o
