#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node *next;
} *head= NULL;

void push(int x) {
  struct Node *t=(struct Node*)malloc(sizeof(struct Node));

  if(t==NULL) 
    printf("stack is full\n");
  else
    t->data=x;
    t->next=head;
    head=t;
}

int pop() {
  struct Node *t;
  int x=-1;
  
  if(head == NULL) {
    printf("Stack is empty \n");
  }
  else {
    t = head;
    head = head->next;
    x=t->data;
    free(t);
  }
  return x;
}

void display() {
  struct Node *p;
  p = head;
  while(p != NULL) {
      printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}


int main() {

  push(10);
  push(20);
  push(30);
  display();
  pop();
  display();

  
  return 0;
}