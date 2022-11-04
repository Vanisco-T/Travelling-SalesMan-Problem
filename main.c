//The main program
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int main(){
    printf("\n============================================\n");
    printf("===IMPLEMENTATION DU VOYAGEUR DE COMMERCE===\n");
    printf("============================================\n");
    int n;
    printf("\n\nEntre la valuer de n pour genere le graph:");
    scanf("%d",&n);
    int** graph=generate(n);
    printf("Le graph d'adjacence est le suivant:\n");
    print(graph,n);
    return 0;
}