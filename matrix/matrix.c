#include <stdlib.h>
#include <stdio.h>


struct Matrix {
  int dataset[10];
  int n;
};



void set(struct Matrix *m, int i, int j, int x) {
  if(i == j) {
    m->dataset[i - 1] = x;
  } 
}


int get(struct Matrix m, int i, int j) {
  if(i == j) {
    return m.dataset[i - 1];
  } 

  return 0;
}


void display(struct Matrix m) {
  int i,  j;

  for(i = 0; i < m.n; i++) {
    for(j = 0; j < m.n; j++) {
      if(i == j) {
          printf("%d ", m.dataset[i]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}


// [
// [1,0,0]
// [2,7,0],
// [5,8,3],
// [9,10,12]
// ]
//




[1, 2, 7, 5, 8, 3, 9, 10, 12]

int main() {

  struct Matrix m;
  m.n = 4;
  set(&m,1,1,5);set(&m,2,2,8);set(&m,3,3,9);set(&m,
  4,4,12);
  display(m);
  return 0;
}



