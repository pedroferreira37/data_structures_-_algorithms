// we using queue to create the tree with linked list

#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
  int size;
  int front;
  int rear;
  Node **Q;
};

void create(struct Queue *q, int size); 

void enqueue(struct Queue *q, Node *x) ;

Node *dequeue(struct Queue *q) ;

int isEmpty(struct Queue q) ;

#endif
