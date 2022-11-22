//The main program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"
#include "main.h"
#include "sequential.h"

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
    int choix;
    printf("Choisir La Procdure A Execute\n");
    printf("     1-Pour Sequentiel   2-Distribue   \n");
    scanf("%d",&choix);
    switch (choix){
    case 1:
       t = clock();
        int res=tsp(st,0,graph);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("TSP Sequential took %f seconds to execute\n and result:%d\n", time_taken,res);
        break;
    case 2:
        printf("TO BE CONTINUED.....\n");
        break;
    default:
        break;
    }
    return 0;
}