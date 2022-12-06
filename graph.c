/*This the function is to generate the adjacent matrix for
  The traveling sales man problem
 */
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include <time.h>



//The adjacent cities contain value between 1 and 10
int** generate(int n){
    FILE *fptr;
    int **p;
    p=malloc(sizeof(int*)*n);
    fptr = fopen("graph.txt", "w+");
    for (int i = 0; i < n; i++){
       p[i]=malloc(sizeof(int*)*n);
    }
    srand(time(NULL));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
               if(i==j){
                p[i][j]=0;
                fprintf(fptr, "%d ",0);
               }
               else{
                int r=rand()%10+1;
                p[i][j]=r;
                p[j][i]=p[i][j];
                fprintf(fptr, "%d ",r);
               }
            } 
        fprintf(fptr, "\n"); 
    } 
    fclose(fptr);
    return p;  
}

void print(int** arr,int n){
    for (int i = 0; i < n; i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
            printf("\n");
    }
    
}

