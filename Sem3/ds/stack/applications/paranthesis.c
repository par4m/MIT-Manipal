#include <stdio.h>
#include <stdlib.h>
// 1) Create Empty Stack
// 2) Scan the symbols of expressions from left to right
// 3) If the symbol is a left bracket, then push that symbol onto the stack
// 4) if the symbol is a right bracket, do the following
//  - if the stack is empty
//    print invalid expression: right brackets are more than left brackets
//  - pop an element from the stack
//    if the popped bracket does not match with right bracket print invalid
//    expression: Mismatched brackets
//  5) After scanning all the symbols of the expression
//  - if stack is empty : print valid expression
//  - else invalid expression : left brackets are more than right
//

#define MAX 20

typedef struct {
  char data[MAX];
  int top;

} STACK;

void init(STACK *s) { s->top = -1; }
void push(STACK *s, char x) {
  if (s->top == MAX - 1) {
    printf("STACK IS FULL");
    return;
  } else {
    s->top++;
    s->data[s->top] = x;
  }
}

char pop(STACK *s) {
  if (s->top == -1) {
    printf("Stack empty");
    exit(1);
  }
  int popped = s->data[s->top];
  s->top--;
  return popped;
}

int isOpening(char x) {
  char chars[] = {'(', '{', '['};
  for (int i = 0; i < 3; i++) {
    if (x == chars[i]) {
      return 1;
    }
  }
  return 0;
}

int isClosing(char x) {
  char arr1[] = {'}', ']', ')'};
  for (int i = 0; i < 3; i++) {
    if (arr1[i] == x) {
      return 1;
    }
  }
  return 0;
}

int checkSame(char popped, char x) {
  if (popped == '(' && x == ')') {
    return 1;
  }
  if (popped == '{' && x == '}') {
    return 1;
  }
  if (popped == '[' && x == ']') {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char *argv[]) {

  STACK s;
  int top;
  int popped;
  init(&s);
  char x;
  printf("Enter Brackets: ");
  while ((x = getchar()) != '\n') {

    if (isOpening(x) == 1) {
      push(&s, x);
    } else {
      if (isClosing(x) == 1) {
        if (s.top == -1) {
          printf("Stack Empty, Invalid Expression");
          return 1;
        } else {
          popped = pop(&s);
          // check if popped (opening) matches the same closing
          if (checkSame(popped, x) != 1) {
            printf("Bracket Mismatched");
            return 1;
          }
        }
      }
    }
  }
  if (s.top == -1) {
    printf("Paranthesis Balanced\n");
  } else {
    printf("Left brackets are more than right brackets\n");
    return 1;
  }
  return 0;
}
