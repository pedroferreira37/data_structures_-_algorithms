
#ifndef NODE_H
#define NODE_H

typedef struct Node {
  struct Node *left;
  struct Node *right;
  int data;
} Node;

#endif
