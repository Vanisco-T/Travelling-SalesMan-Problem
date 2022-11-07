tsp : main.o graph.o sequential.o
	gcc -o tsp main.o graph.o sequential.o
main.o : main.c graph.c
		  gcc -c main.c graph.c
graph.o : graph.c 
		gcc -c graph.c
sequential.o : sequential.c
		gcc -c sequential.c