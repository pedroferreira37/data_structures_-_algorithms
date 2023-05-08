#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n == 0)
    return 1;

  return n * factorial(n - 1);
}

int fac(int n) { int t; }

int fib(int n) {
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return fib(n - 1) + fib(n - 2);
}

int sum(int arr[], int n) {

  if (n <= 0) {
    return 0;
  }

  return arr[n - 1] + sum(arr, n - 1);
}

struct Node {
  int data;
  struct Node *next;
} *head;

struct Node *LinkedList(int arr[], int n) {
  struct Node *head, *cur;

  head = (struct Node *)malloc(sizeof(struct Node));

  head->data = arr[0];

  head->next = NULL;

  cur = head;

  for (int i = 1; i < n; i++) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = arr[i];

    temp->next = NULL;

    cur->next = temp;

    cur = cur->next;
  }

  free(cur);
  return head;
}

void display(struct Node *head) {
  if (head == NULL)
    return;

  if (head->next == NULL) {
    printf("%d", head->data);
  } else {
    printf("%d->", head->data);
  }

  display(head->next);
}

void reverseLinkedList(struct Node *q, struct Node *p) {

  if (p) {
    reverseLinkedList(p, p->next);
    p->next = q;
  } else {
    head = q;
  }
}

int len(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i)
    ;
  return i;
}

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(char str[], int l, int h) {

  if (l < h) {
    swap(&str[l], &str[h]);
    reverse(str, l + 1, h - 1);
  }
}

void merge(int a[], int i, int b[], int j, int r[]) {

  if (i != 0 || j != 0) {
    if (i == 0) {
      r[0] = b[0];
      merge(a, i, b + 1, j - 1, r + 1);
    } else if (j == 0) {
      r[0] = a[0];
      merge(a + 1, i - 1, b, j, r + 1);
    } else if (a[0] < b[0]) {
      r[0] = a[0];
      merge(a + 1, i - 1, b, j, r + 1);
    } else {
      r[0] = b[0];
      merge(a, i, b + 1, j - 1, r + 1);
    }
  }
}

int maxElement(int a[], int i) {

  if (i == 1)
    return a[i - 1];

  int max = maxElement(a, i - 1);

  if (max > a[i - 1])
    return max;
  else
    return a[i - 1];
}

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int arr2[5] = {6, 7, 8, 9, 10};
  int res[10];

  printf("%d", maxElement(arr2, 5));

  // merge(arr, 5, arr2, 5, res);

  // for (int i = 0; i < 10; i++) {
  // printf("%d", res[i]);
  // }
  // head = LinkedList(arr, len(arr, 5));
  // struct Node *node = LinkedList(arr, len(arr, 5));
  // display(head);
  // reverseLinkedList(NULL, head);
  // display(head);
  // printf("fact: %d \n", factorial(3));
  // printf("fib: %d", fib(5));
  // printf("sum of nums %d", sum(arr, 5));

  return 0;
}
