//This file is for the second version
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "stack.h"
#include "sequential.h"
#include "main.h"
#include "distributed.h"
#include "pthread.h"

 

int st,n,cost;
int** graph;
int min_path;
Stack sta;

Stack Generate_Task(int n_hops){
    int* vec=(int*)malloc(n_hops*sizeof(int));
    //Le tableau du reste de ville qui serait permuter
    for (int i = 0; i < n_hops; i++)
            vec[i]=i;
    //Elimination de la ville du depart dans le tableau
    for(int c=st;c<n_hops;c++)
            vec[c]=vec[c+1];
    n_hops--;

    //On cree la queue en ensuite on ajoute tous les differente
    //permutation dans la queue
    Stack sta1=new_stack();
    int *temp;
     do{  
        temp=calloc(n_hops,sizeof(int));
        for (int i = 0; i < n_hops; i++){
           temp[i]=vec[i];
        }
        sta1=push_stack(sta1,temp);        
    } while (next_permutation(vec,0,n_hops-1));  
    return sta1;
} 
void* Do_Work(void* no){
    int current_cost=0;
     do {
    int* tab=(int*)malloc((n-1)*sizeof(int));
    tab=top_stack(sta);
    sta=pop_stack(sta);
      int k=st;
      for (int i = 0; i < n-1; i++){
                current_cost += graph[k][tab[i]];
                k=tab[i];  
        }
        current_cost += graph[k][st];
        min_path=min(current_cost,min_path); 
    } while (is_empty(sta)); 
    return NULL;
}
int multi(int n_cities,int n_threads,int max_hops){
    min_path=INT_MAX;
    sta=Generate_Task(n_cities);
    pthread_t num[n_threads];  
    for (int i = 0; i < n_threads; i++){
        num[i]=i+1;
    }
    for(int i = 0; i < n_threads; i++) {
       pthread_create(&num[i], NULL,&Do_Work,NULL);
    }
    for(int i = 0; i < n_threads; i++) {
        pthread_join(num[i], NULL);
    } 
    return min_path;
}




