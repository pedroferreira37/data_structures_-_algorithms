#include <stdlib.h>
#include <stdio.h>


struct Matrix {
  int A[10];
  int n;
};



void set(struct Matrix *matrix, int i, int j, int x) {
  if(i == j) {
    matrix->A[i - 1] = x;
  } 
}


int get(struct Matrix matrix, int i, int j) {
  if(i == j) {
    return matrix.A[i - 1];
  } 

  return 0;
}


void display(struct Matrix  matrix) {
  int i,  j;

  for(i = 0; i < matrix.n; i++) {
      for(j = 0; j < matrix.n; j++) {
      if(i == j) {
          printf("%d ", matrix.A[i]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}



int main() {

  struct Matrix m;
    m.n = 4;
  set(&m,1,1,5);set(&m,2,2,8);set(&m,3,3,9);set(&m,
  4,4,12);
  display(m);
  return 0;
}



