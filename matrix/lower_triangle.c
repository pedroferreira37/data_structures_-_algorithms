#include <stdlib.h>
#include <stdio.h>




struct Matrix {
  int* A;
  int n;
};



void set(struct Matrix *matrix, int i, int j, int x) {
  if(i >=  j) {
    //row mapping
    matrix->A[i * ( i - 1) / 2 + j - 1] = x;
    // columnn mapping
    // matrix->A[m->n*(j - 1) +  (j - 2) * (j - 1) / 2 + j - i]
  } 
}


int get(struct Matrix matrix, int i, int j) {
  if(i >= j) {
    return matrix.A[i * ( i - 1) / 2 + j - 1];
    // columnn mapping
    // matrix->A[m->n*(j - 1) +  (j - 2) * (j - 1) / 2 + j - i]

  } 

  return 0;
}


void display(struct Matrix  matrix) {
  int i,  j;

  for(i = 1; i < matrix.n; i++) {
      for(j = 1; j < matrix.n; j++) {
      if(i >=  j) {
          printf("%d ", matrix.A[i * ( i - 1) / 2 + j - 1]);
    // columnn mapping
    // matrix->A[m->n*(j - 1) +  (j - 2) * (j - 1) / 2 + j - i]

      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}



int main() {

  struct Matrix m;
 int i,j,x;

   printf("Enter Dimension");
   scanf("%d",&m.n);
   m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));
   printf("enter all elements");
   for(i=1;i<=m.n;i++){

     for(j=1;j<=m.n;j++){
       scanf("%d",&x);
       set(&m,i,j,x);
     }
 }
   printf("\n\n");
    display(m);
    return 0;
}



