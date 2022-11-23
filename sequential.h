//The .h file for the sequential version
#include <stdbool.h>
int tsp(int last_city,int current_cost,int** graph);
void pswap(int *l,int *r);
void reverse(int A[],int l,int r);
int min(int a,int b);
bool next_permutation(int A[],int l,int r);
