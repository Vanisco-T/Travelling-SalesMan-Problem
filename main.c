//The main program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "main.h"
#include "sequential.h"
#include "distributed.h"

 int st,n,cost=0;
 int** graph;
int main(){
    clock_t t;
    printf("\n============================================\n");
    printf("===IMPLEMENTATION DU VOYAGEUR DE COMMERCE===\n");
    printf("============================================\n");
    printf("\n\nEntre la valuer de n pour genere le graph:");
    scanf("%d",&n);
    graph=generate(n);
    printf("Le graph d'adjacence est le suivant:\n");
    print(graph,n);
    printf("Choisir un point de depart entre 0 et %d:\n\n",n-1);
    scanf("%d",&st);
        t = clock();
        int res=tsp(st,0,graph);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("TSP Sequential took %f seconds to execute\n and result:%d\n", time_taken,res);
        t=clock();
        int res1=multi(n,n-1,n);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("TSP Multi-thread took %f seconds to execute\n and result:%d\n", time_taken,res1);
    return 0;
}