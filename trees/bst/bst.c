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
    printf("%d ", p->data);
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

struct Node *RInsert(struct Node *p, int key) {
  struct Node *t;

  if (p == NULL) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->left = t->right = NULL;
    return t;
  }
  if (key < p->data) {
    p->left = RInsert(p->left, key);
  } else if (key > p->data) {
    p->right = RInsert(p->right, key);
  }

  return p;
}

int Height(struct Node *p) {
  int x, y;

  if (p == NULL)
    return 0;

  x = Height(p->left);
  y = Height(p->right);

  return x > y ? x + 1 : y + 1;
}

struct Node *InPre(struct Node *p) {
  while (p && p->right != NULL) {
    p = p->right;
  }

  return p;
}

struct Node *InSuc(struct Node *p) {
  while (p && p->left != NULL) {
    p = p->left;
  }

  return p;
}

struct Node *Delete(struct Node *p, int key) {
  struct Node *q;

  if (p == NULL)
    return NULL;
  if (p->left == NULL && p->right == NULL) {
    if (p == root) {
      root = NULL;
    }
    free(p);
    return NULL;
  }

  if (key < p->data) {
    p->left = Delete(p->left, key);
  } else if (key > p->data) {
    p->right = Delete(p->right, key);
  } else {
    if (Height(p->left) > Height(p->right)) {
      q = InPre(p->left);
      p->data = q->data;
      p->left = Delete(p->left, q->data);
    } else {
      q = InSuc(p->right);
      p->data = q->data;
      p->right = Delete(p->right, q->data);
    }
  }

  return p;
}

int main() {
  root = RInsert(root, 10);
  RInsert(root, 5);
  RInsert(root, 20);
  RInsert(root, 8);
  RInsert(root, 30);

  Inorder(root);
  printf("\n");
  struct Node *f = Delete(root, 20);

  Inorder(root);

  if (f) {
    printf("Found");
  }

  return 0;
}
