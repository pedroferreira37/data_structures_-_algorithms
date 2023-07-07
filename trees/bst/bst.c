#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *left;
  int data;
  struct Node *right;
} *root = NULL;

void Insert(int key) {
  struct Node *t = root;
  struct Node *r, *p;

  if (root == NULL) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->left = p->right = NULL;
    root = p;
    return;
  }

  while (t != NULL) {
    r = t;
    if (key < t->data) {
      t = t->right;
    } else if (key > t->data) {
      t = t->right;
    } else {
      return;
    }
  }

  p = (struct Node *)malloc(sizeof(struct Node));
  p->data = key;
  p->left = p->right = NULL;

  if (key < r->data)
    r->left = p;
  else
    r->right = p;
}

void Inorder(struct Node *p) {
  if (p) {
    Inorder(p->left);
    printf("%d", p->data);
    Inorder(p->right);
  }
}

struct Node *Search(int key) {
  struct Node *t = root;

  while (t != NULL) {
    if (key == t->data)
      return t;
    else if (key < t->data) {
      t = t->left;
    } else {
      t = t->right;
    }
  }

  return NULL;
}

int main() {
  Insert(10);
  Insert(5);
  Insert(20);
  Insert(8);
  Insert(30);

  Inorder(root);
  printf("\n");

  struct Node *f = Search(20);

  if (f) {
    printf("Found");
  }

  return 0;
}
