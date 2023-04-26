#include <stdlib.h>
#include <stdio.h>

// Write a recursive function to calculate the factorial of a given number. Ok
// Write a recursive function to calculate the nth Fibonacci number. Ok
// Write a recursive function to find the sum of all elements in an array. Ok
// Write a recursive function to reverse a linked list.
// Write a recursive function to check if a string is a palindrome.
// Write a recursive function to find the greatest common divisor (GCD) of two numbers.
// Write a recursive function to find the power of a number.
// Write a recursive function to merge two sorted arrays into a single sorted array.


int factorial(int n) {  
  if(n == 0) return 1;

  return n * factorial(n - 1);
}

int fib(int n) {
  if(n == 0) return 0;

  if(n == 1) return 1;

  return fib(n - 1) + fib(n - 2);
}


int sum(int arr[], int n) {

  if(n <=  0) {
    return 0;
  }

  return arr[n - 1] + sum(arr, n - 1);
}



struct Node { 
  int data; 
  struct Node *next;
}; 


struct Node*  createLL(int arr[], int n ){
  struct Node *head, *cur;
 head = (struct Node *) malloc(sizeof(struct Node));
  head->data = arr[0];
 head ->next = NULL;
  
  cur = head;
  for(int i = 1; i < n; i++) {
    struct Node* p = (struct Node *) malloc(sizeof(struct Node));
    p->data = arr[i];
    p->next = NULL;
    cur->next = p;
    cur  = cur->next;
  }


  return head;
}


void displayLL(struct Node* head) {
    if(!head) return;

    printf("%d->", head->data);

    displayLL(head->next);
}


struct Node* reverseR(struct Node* head) {
  if(head == NULL) return NULL;

  if(first->link == NULL) return head;
}

struct Array {
  int [];
  int size;
  int length;
};

//
// int len(void str[]) {
//   int i;
//   for(i = 0; str[i] != '\0'; ++i);   
//   return i;
// }
//
//
//
// void swap(char *a, char *b) {
//   char temp = *a;
//   *a = *b;
//   *b = temp;
// }
//
//
//
// void  reverse(char str[], int l, int h) {
//
//   if(l < h) {
//     swap(&str[l], &str[h]);
//     reverse(str, l + 1, h -  1);
//     }




int main(void) {
  int arr[5] = { 1, 2, 3, 4, 5};
  struct Node* node = createLL(arr, 5);
    displayLL(node);
  // printf("fact: %d \n", factorial(3));
  // printf("fib: %d", fib(5));
    // printf("sum of nums %d", sum(arr, 5));

  
  return 0;
}
