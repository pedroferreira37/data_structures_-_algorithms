#include "node.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

struct Node *root = NULL;

void createTree() {
  struct Node *p, *t;
  int x;
  struct Queue q;

  create(&q, 100);
  printf("Enter root value");
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->left = root->right = NULL;
  enqueue(&q, root);

  while (!isEmpty(q)) {
    p = dequeue(&q);

    printf("Enter left child of %d", p->data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *)malloc(sizeof(Node *));
      t->data = x;
      t->left = t->right = NULL;
      p->left = t;
      enqueue(&q, t);
    }

    printf("Enter right child of %d", p->data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *)malloc(sizeof(Node *));
      t->data = x;
      t->left = t->right = NULL;
      p->right = t;
      enqueue(&q, t);
    }
  }
}

int preoder(struct Node *p) {

  if (p) {
    printf("%d", p->data);
    preoder(p->left);
    preoder(p->right);
  }
}

int main(int argc, char **argv) {
  createTree();
  preoder(root);

  return 0;
}
