#include "stdio.h"
#include "stdlib.h"
#define MAX 20

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *s[MAX];
int top = -1;

int IsEmpty() {
  if (top == -1) {
    return 1;
  }
  return 0;
}

void push(struct Node *n) {

  if (top == MAX - 1) {
    printf("cant push");
    return;
  }
  top++;
  s[top] = n;
}

struct Node *pop() {
  if (top == -1) {
    printf("Empty, cannot Pop");
  } else {
    return s[top--];
  }
}

// Recursive Creation

struct Node *create() {
  int x;
  struct Node *newNode = malloc(sizeof(struct Node));
  printf("\nEnter data (-1 for no Node): ");
  scanf("%d", &x);
  if (x == -1) {
    return 0;
  }
  newNode->data = x;
  printf("\nEnter the left child of %d  ", x);
  newNode->left = create();
  printf("\nEnter the right child of %d", x);
  newNode->right = create();
  return newNode;
}

// Iterative Creation

// Traversals

// PreOrder - Root Left Right
// PostOrder - Left Right Root
// InOrder - Left Root Right

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
void InOrder(struct Node *root) {
  if (root) {
    InOrder(root->left);
    printf("%d", root->data);
    InOrder(root->right);
  }
}

// Iterative InOrder traversal
// 1. create Empty Stack S
// 2. Initialise current node as root
// 3. Push current node to Stack and set current = current -> left until current
// is NULL
// 4. If current is NULL and stack is not empty then
//     - Pop the top from stack
//     - Print the popped item, set current = popped_item -> right
//     - Go to step 3
// 5. If current is NULL and stack is empty then end

void Iterative_inorder(struct Node *root) {

  struct Node *current = root;
  int done = 0;
  while (!done) {
    while (current) {
      push(current);
      current = current->left;
    }
    if (top != -1) {
      current = pop();
      printf("%d", current->data);
      current = current->right;
    } else {
      done = 1;
    }
  }
}

void iterative_preorder() {}

void iterative_postorder() {}

int main(int argc, char *argv[]) {

  struct Node *root;
  root = create();
  printf("\nPre Order: ");
  PreOrder(root);
  printf("\nPost Order: ");
  PostOrder(root);

  printf("\nInOrder: ");
  InOrder(root);

  printf("\nIterative InOrder: ");

  Iterative_inorder(root);

  return 0;
}
