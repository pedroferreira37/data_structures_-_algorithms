#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int col;
  int val;
  struct Node* next;
} Node;

typedef struct Sparse {
  int m;
  int n;
  Node** node;
} Sparse;

Sparse* create_sparse_matrix() {
  Sparse* s = (Sparse*)malloc(sizeof(Sparse));

  printf("Enter the number of rows and columns: ");
  scanf("%d %d", &s->m, &s->n);

  s->node = (Node**)malloc(s->m * sizeof(Node*));
  for (int i = 0; i < s->m; i++) {
    s->node[i] = NULL;
  }

  int num_nonzero;
  printf("Enter the number of nonzero elements: ");
  scanf("%d", &num_nonzero);

  for (int i = 0; i < num_nonzero; i++) {
    int row, col, val;
    printf("Enter row, column, and value of element %d: ", i + 1);
    scanf("%d %d %d", &row, &col, &val);

    if (row >= s->m || col >= s->n) {
      printf("Invalid row or column index\n");
      i--;
      continue;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->col = col; //1
    new_node->val = val; // 2
    new_node->next = NULL; //row = 0

 
    
    if (s->node[row] == NULL) {
      s->node[row] = new_node;
    } else {
      Node* current = s->node[row]; // 0 1 -> null
      Node* prev = NULL;
      while (current != NULL && current->col < col) {
        prev = current;
        current = current->next; 
      }

      // prev =  0 1 -> null
      //current = null

      if (current != NULL && current->col == col) {
        current->val = val;
        free(new_node);
      } else {
        if (prev == NULL) {
          s->node[row] = new_node;
        } else {
          prev->next = new_node;
          // prev =  0 1 -> 1 2
        }
        new_node->next = current;
        // 1 2 -> null
         // s->node[i] =  0 1 -> 1 2 -> null
      }
    }
  }

  return s;
}

void print_sparse_matrix(Sparse* s) {
  printf("Sparse matrix: \n");
  for (int i = 0; i < s->m; i++) {
    for (int j = 0; j < s->n; j++) {
      if (s->node[i] == NULL || s->node[i]->col > j) {
        printf("0 ");
      } else {
        printf("%d ", s->node[i]->val);
        s->node[i] = s->node[i]->next;
      }
    }
    printf("\n");
  }
}

int main() {
  Sparse* s = create_sparse_matrix();
  print_sparse_matrix(s);
  return 0;
}