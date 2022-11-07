//The sequential version
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include "sequential.h"
#include <limits.h>
int st,n,cost;
int** graph;

int visited[10];
void setVisited(){
    for (int i = 0; i < n; i++){
        visited[i]=0;
    }
}  
//Set visited to 0
//Find the next Node
int find_next_node(int node){
    int nd,min=INT_MAX,min_index=INT_MAX,democost,i;
    for ( i = 0; i < n; i++){
        if (!visited[i] && graph[node][i]!=0 && graph[node][i]<min){
             democost=graph[node][i];
             min=graph[node][i];
             min_index=i;
        }  
    }
    nd=min_index;   
    cost +=democost;
    return nd;
}
//Travelling salesman fonction
void tsp(int last_city,int current_cost,int** graph){

    int next_node;
    next_node=find_next_node(last_city); 
    if (next_node == INT_MAX){
        printf("We reach the last node:%d\n",last_city);
        int v=st;
        printf("\nDistance from last city(%d) to start (%d):%d\n",last_city,st,graph[last_city][v]);
        cost += graph[last_city][v];
        printf("The final cost is : %d\n",cost);
    }
    else{
    visited[last_city]=1;
    printf("The new cost is %d and the city visited is: %d\n",cost,last_city); 
    tsp(next_node,cost,graph);
    }  
}


