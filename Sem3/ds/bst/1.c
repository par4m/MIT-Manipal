#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *insert(struct Node *root, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (root == NULL) {
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

void PreOrder(struct Node *root) {
  if (root) {
    printf("%d", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
  }
}

void PostOrder(struct Node *root) {
  if (root) {
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d", root->data);
  }
}

int main(int argc, char *argv[]) {

  struct Node *root;
  root = NULL;
  int ch;
  do {
    printf("\n1. Insert");
    printf("\n2. PreOrder");
    printf("\n3. PostOrder");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    if (ch == 1) {
      int x;
      do {
        printf("Enter data: (-1 go back) :  ");
        scanf("%d", &x);
        if (x == -1) {
          break;
        }
        root = insert(root, x);
      } while (x != -1);
    }
    if (ch == 2) {
      printf("\nPreOrder : ");
      PreOrder(root);
    }
    if (ch == 3) {
      printf("\nPostOrder");
      PostOrder(root);
    }

  } while (ch != -1);

  return 0;
}
