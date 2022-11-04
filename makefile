tsp : main.o graph.o
	gcc -o tsp main.o graph.o
main.o : main.c graph.c
		  gcc -c main.c graph.c
graph.o : graph.c 
		gcc -c graph.c