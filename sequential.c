//The sequential version
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "sequential.h"
#include <limits.h>
int st,n,cost;
int** graph;

int min(int a,int b){
    return (a<b) ? a : b;
}
void pswap(int *l, int *r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}
void reverse(int A[], int l, int r) {
    while (l < r) {
        pswap(&A[l++], &A[r--]);
    }
}
bool next_permutation(int A[],int l,int r){
     int j = r; // j will point to the highest peak of the interval [i,r].
  // this loop will find the first increasing [i,j] from r to l.
  while (j > l) {
      if (A[j-1] < A[j]) {
          break;
      }
      --j;
  }
  if (j > l) {
      int k = r;
      // find the first A[k] where A[k] > A[j-1].
      while (!(A[j-1] < A[k])) {
          --k;
      }
      pswap(&A[j-1], &A[k]);
      reverse(A, j, r);
      return true;
  }

  reverse(A, j, r);
  return false;
}



//Travelling salesman fonction
int tsp(int last_city,int current_cost,int** graph){
    int* vec=(int*)malloc(n-1*sizeof(int));
    for (int i = 0; i < n; i++){
        if(i !=last_city)
            vec[i]=i;
    }
    int min_path=INT_MAX;
    do{
        int current_pathweight = 0;
        int k=last_city;
        for (int i = 0; i < n-1; i++){
            current_pathweight += graph[k][vec[i]];
            k=vec[i];
        }
        current_pathweight += graph[k][last_city];
        min_path = min(min_path,current_pathweight);
    } while (next_permutation(vec,0,n-1));
    
  return min_path;     
}


