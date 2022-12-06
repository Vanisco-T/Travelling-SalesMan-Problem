//Tne .h for the distributed version
#include "stack.h"
Stack Generate_Task(int n_hops);
void* Do_Work(void* no);
int multi(int n_cities,int n_threads,int max_hops);
extern pthread_mutex_t mutex;
extern pthread_mutex_t mutex1;


