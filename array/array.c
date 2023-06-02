#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct Array {
  int A[10];
  int size;
  int length;
};
void Display(struct Array arr) {
  int i;
  printf("\nElements are\n");
  for (i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
}
void Append(struct Array *arr, int x) {
  if (arr->length < arr->size)
    arr->A[arr->length++] = x;
}
void Insert(struct Array *arr, int index, int x) {
  int i;

  if (index >= 0 && index <= arr->length) {
    for (i = arr->length; i > index; i--)
      arr->A[i] = arr->A[i - 1];
    arr->A[index] = x;
    arr->length++;
  }
}

void Delete(struct Array *arr, int index) {
  int x = 0;

  if (index >= 0 && index < arr->length) {
    x = arr->A[index];
    for (int i = index; i < arr->length - 1; i++) {
      arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
  }
}

int Get(struct Array arr, int index) {
  if (index >= 0 && index < arr.length) {
    return arr.A[index];
  }
  return -1;
}

void Set(struct Array *arr, int index, int x) {
  if (index >= 0 && index < arr->length) {
    arr->A[index] = x;
  }
}

int Max(struct Array arr) {
  int max = arr.A[0];
  for (int i = 1; i < arr.length; i++) {
    if (arr.A[i] > max) {
      max = arr.A[i];
    }
  }
  return max;
}

int Min(struct Array arr) {
  int min = arr.A[0];
  for (int i = 1; i < arr.length; i++) {
    if (arr.A[i] < min) {
      min = arr.A[i];
    }
  }
  return min;
}

int Sum(struct Array arr) {
  int s = 0;
  for (int i = 0; i < arr.length; i++) {
    s += arr.A[i];
  }
  return s;
}

float Avg(struct Array arr) { return (float)Sum(arr) / arr.length; }

void swap(int *x, int *y) {
  int temp;

  temp = *x;
  *x = *y;
  *y = temp;
}

void reverse(struct Array *arr) {
  int *B;

  B = (int *)malloc(arr->length * sizeof(int));

  for (int i = arr->length - 1, j = 0; i >= 0; i--, j++) {
    B[j] = arr->A[i];
  }

  for (int i = 0; i < arr->length; i++) {
    arr->A[i] = B[i];
  }
}

void reverse_two(struct Array *arr) {
  for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
    swap(&arr->A[i], &arr->A[j]);
  }
}

int linear(struct Array *arr, int key) {
  for (int i = 0; i < arr->length; i++) {
    if (key == arr->A[i]) {
      swap(&arr->A[i], &arr->A[i - 1]);
      return i;
    }
  }
  return -1;
}

void insert_sorted(struct Array *arr, int x) {
  int i = arr->length - 1;
  if (arr->length == arr->size)
    return;
  while (i >= 0 && arr->A[i] > x) {
    arr->A[i + 1] = arr->A[i];
    i--;
  }
  arr->A[i + 1] = x;
  arr->length++;
}

bool isSorted(struct Array arr) {
  int i;
  for (i = 0; i < arr.length - 1; i++) {
    return false;
  }
  return true;
}

void re_arrange(struct Array *arr) {
  int i = 0;
  int j = arr->length -1;
  while(i < j) {
    while(arr->A[i] < 0) i++;
    while(arr->A[i] >= 0) j--;
    if(i < j)swap(&arr->A[i], &arr->A[j]);
  }
}

struct Array* merge(struct Array *arr, struct Array *arr2) {
  int i,j, k;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while(i < arr->length && j < arr2->length) {
    i =0, j=0, k=0;
    if(arr->A[i]  < arr2->A[j]) {
      arr3->A[k++] = arr->A[i];
    } else {
      arr3->A[k++] = arr2->A[j++];
    }
  }

  for(;i<arr->length;i++) {
    arr3->A[k++] = arr->A[i];
  }
   for(;j<arr2->length;j++) {
    arr3->A[k++] = arr2->A[i];
  }

  arr3->length = arr->length + arr2->length;
  arr3->size=10;
  return arr3;
}


void print(struct Array arr) {
  for (int i = 0; i < arr.length; i++) {
    printf("%d", arr.A[i]);
  }
}

int main() {
// struct Array arr = {{1, 2, 3}, 10, 3};
 // struct Array arr_2 = {{2, 3, 5, 10, 15}, 10, 5};
   struct Array arr = {{2,6,10,15,25}, 10, 5};
   struct Array arr2 = {{3,4,7,18,22}, 10, 5};
  struct Array *arr3;

  arr3 = merge(&arr, &arr2);

  // reverse(&arr);
  // reverse_two(&arr);
  // print(arr_2);
  // insert_sorted(&arr_2, 1);
  //  print(arr_2);
  // printf("%d\n", linear(&arr, 2));
 // re_arrange(&arr);
  print(*arr3);
  //re_arrange(&arr);
  //print(arr);

  return 0;
}
