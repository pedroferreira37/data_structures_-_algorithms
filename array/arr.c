#include <stdio.h>
#include <stdlib.h>
#include <math.h>




struct Array  {
  int length;
  int size;
  int A[20];
};






void printWithBrackets(struct Array arr) {
  printf("[");
  for(int i = 0; i < arr.length; i++ ) {
    if(i < arr.length - 1) {
      printf("%d,", arr.A[i]);
    } else {
      printf("%d", arr.A[i]);
    }
  }
  printf("]");
}


void push(struct Array* arr, int x) {
   arr->A[arr->length] = x;
   arr->length++;
}



//my code
void insert(struct Array* arr, int index, int x) {
    if(index < arr->length) { 
        int i = arr->length;
        while(i > index) {
          arr->A[i] = arr->A[i - 1];
          i--;
        }

        arr->A[index] = x;
        arr->length++;
    }
};


//professor code


void insertTwo(struct Array* arr, int index, int x) {
  for(int i = arr->length; i > index; i--) {
    arr->A[i] = arr->A[i - 1];
  }

  arr->A[index] = x;
  arr->length++;
}


void pop(struct Array* arr) {
  arr->length--;
}

void delete(struct Array* arr, int index) {
  for(int i = index; i <  arr->length; i++) {
    arr->A[i] = arr->A[i + 1];
  }

  arr->length--;
}

void ls(struct Array* arr, int num) {
  for(int i = 0; i < arr->length; i++) {
    if(arr->A[i] == num) {
      printf("%d", i);
      return;
    }
  }
}

int  BS(struct Array* arr, int key) {

  int start = 0;
  int end = arr->length - 1;
  int m;

  while(start <= end) {

     m = floor(((start + end) / 2)) ;
    if(arr->A[m] == key) {
      return m;
    } else if(key < arr->A[m]) {
      end  = m - 1;
    } else  {
      start = m + 1;
    }  
  }

  return -1;

}


int get(struct Array* arr, int index) {
  return arr->A[index];
}


int set(struct Array* arr, int index, int x) {
  if(index >= 0 && index < arr->length) {
     arr->A[index] = x;
      arr->length++;
    }
 }


int max(struct Array arr) {
  int i = arr.A[0];

  for(int i = 0; i < arr.length; i++) {
    if(arr.A[i] > i) {
      i = arr.A[i];
    }
  }

  return i;
}


int swap(struct Array* arr, int head, int n) {
  int temp =  arr->A[head];
  arr->A[head] = arr->A[n];
  arr->A[n] = temp;
}

void reverse(struct Array* arr) {
  int i = 0;
  int j = arr->length - 1;

  
  while(i <= j) {
    swap(arr, i, j);
    i++;
    j--;
  }

}

void reverseRecurse(struct Array* arr, int head, int n) {
  if(head < n) {
    swap(arr, head, n);
    reverseRecurse(arr, head + 1, n - 1);
  }
}

int sum(int A[], int n) {
  if(n < 0) {
    return 0;
  } 

  return sum(A, n - 1) + A[n];
}


void shiftLeft(int A[], int n) {
  int j = 0;
  while(j < n) {

  int temp = A[0];

  for(int i = 0; i< n ; i++) {
    A[i] = A[i + 1];
  }
  A[n] = temp;



  for(int i = 0; i< n + 1; i++) {
      printf("%d", A[i]);
    }
  j++;
  }



}


int* merge(int A[], int n, int B[],  int m) {
  int i = 0;
  int j = 0;
  int k = 0;
  int* C = (int *)malloc(sizeof(int) * (m + n));

  while(i < n && j < m) {
    if(A[i] < B[j])  {
      C[k++] = A[i++];
    } else {
      C[k++] = B[j++];
    }
  }

  for(; i < n; i++) {
    C[k++] = A[i];
  }



  for(; j < m; j++) {
    C[k++] = B[j];
  }


  return C;
 }

void c_print(int A[], int n) {
  for(int i = 0; i < n ; i++) {
    printf("%d", A[i]);
  }
}



int main() {
  struct Array arr = {5, 20,{ 1, 2, 3, 4,5}};
    int A[]  = { 1, 2, 3};
    int B[] = { 4, 5, 6};
    int *C = merge(A, 3, B, 3);
    // merge(A, 3, B, 3, C);
    c_print(C, 6);
    
  // push(&arr, 6);
  // insert(&arr, 2, 10);
  // insertTwo(&arr, 3, 11);
  // delete(&arr, 1);
  // pop(&arr);
    // set(&arr, 0, 100);
  // swap(&arr, 0, arr.length - 1);
  // reverse(&arr);
  // reverseRecurse(&arr, 0, arr.length - 1);
  
    // printf("%d", sum(arr2, 4));
    // shiftLeft(arr2, 3);
    // print(arr);
  return 0;
}
