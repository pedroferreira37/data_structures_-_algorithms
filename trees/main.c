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
  printf("Enter root value ");
  scanf("%d", &x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->left = root->right = NULL;
  enqueue(&q, root);

  while (!isEmpty(q)) {
    p = dequeue(&q);

    printf("Enter left child of %d ", p->data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *)malloc(sizeof(Node));
      t->data = x;
      t->left = t->right = NULL;
      p->left = t;
      enqueue(&q, t);
    }

    printf("Enter right child of %d ", p->data);
    scanf("%d", &x);

    if (x != -1) {
      t = (Node *)malloc(sizeof(Node));
      t->data = x;
      t->left = t->right = NULL;
      p->right = t;
      enqueue(&q, t);
    }
  }
}

void preoder(struct Node *p) {

  if (p) {
    printf("%d ", p->data);
    preoder(p->left);
    preoder(p->right);
  }
}

void postorder(struct Node *p) {
  if (p) {
    postorder(p->left);
    postorder(p->right);
    printf("%d", p->data);
  }
}

void inorder(Node *p) {
  if (p) {
    postorder(p->left);
    printf("%d", p->data);
    postorder(p->right);
  }
}

void level_order(Node *root) {
  struct Queue q;

  create(&q, 100);

  printf("%d", root->data);
  enqueue(&q, root);

  while (!isEmpty(q)) {
    root = dequeue(&q);

    if (root->left) {
      printf("%d", root->left->data);
      enqueue(&q, root->left);
    }

    if (root->right) {
      printf("%d", root->right->data);
      enqueue(&q, root->right);
    }
  }
}

int countNodes(Node *p) {
  int x, y;

  if (p) {
    x = countNodes(p->left);
    y = countNodes(p->right);

    return x + y + 1;
  }

  return 0;
}

int main(int argc, char **argv) {
  createTree();
  // preoder(root);
  // postorder(root);
  // postorder(root);
  // level_order(root);
  printf("%d", countNodes(root));

  return 0;
}
