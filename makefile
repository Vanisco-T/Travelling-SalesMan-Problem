tsp : main.o graph.o sequential.o distributed.o stack.o
	gcc -o tsp main.o graph.o sequential.o distributed.o stack.o
main.o : main.c graph.c
		  gcc -c main.c graph.c
graph.o : graph.c 
		gcc -c graph.c
sequential.o : sequential.c
		gcc -c sequential.c
distributed.o : distributed.c 
		gcc -c distributed.c -pthread
stack.o :stack.c
		gcc -c stack.c