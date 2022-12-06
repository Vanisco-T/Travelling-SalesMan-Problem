//The main program
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "graph.h"
#include "main.h"
#include "sequential.h"
#include "distributed.h"

int st,n,cost=0;
int** graph;
pthread_mutex_t mutex;
pthread_mutex_t mutex1;

int main(int argc, char *argv[]){
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_init(&mutex1,NULL);
    int num_thread,num;
    clock_t t;
    printf("\n============================================\n");
    printf("===IMPLEMENTATION DU VOYAGEUR DE COMMERCE===\n");
    printf("============================================\n");
    switch (*argv[1])
    {
    case 'g':
        n=atoi(argv[2]),st=atoi(argv[3]),num_thread=atoi(argv[4]);
        graph=generate(n);
        t = clock();
        int res=tsp(st,0,graph);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        double seq_time=time_taken;
        printf("TSP Sequential time:%f and result %d\n",time_taken,res);
        t=clock();
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_init(&mutex1, NULL);
        int res1=multi(n,num_thread,n);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("TSP Multi-thread time:%f and result %d\n",time_taken,res1);   
        pthread_mutex_destroy(&mutex); 
        break;
    case 'u':
        n=atoi(argv[2]),st=atoi(argv[3]),num_thread=atoi(argv[4]);
        FILE *fptr;
        fptr = fopen("graph.txt", "r");
        graph=malloc(sizeof(int*)*n);
        for (int i = 0; i < n; i++){
            graph[i]=malloc(sizeof(int*)*n);
        }
         for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                fscanf(fptr, "%d", &num);
                graph[i][j] = num;
            }
        }
        t = clock();
        res=tsp(st,0,graph);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        seq_time=time_taken;
       printf("TSP Sequential time:%f and result %d\n",time_taken,res);
        t=clock();
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_init(&mutex1, NULL);
        res1=multi(n,num_thread,n);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
        printf("TSP Multi-thread time:%f and result %d\n",time_taken,res1);   
        pthread_mutex_destroy(&mutex);
        break;
    default:
        break;
    }

    return 0;
}