#include <stdio.h>

// Order of operation
// 1. Paranthesis () {} []
// 2. Exponents (Rigt to left)
// 3. Multiplication and division (left to right)
// 4. Addition and Subtraction (left to right)

// Algorithm
// 1. Go from Left to Right
// 2. If an operand -> directly copy to postfix expression
// 3. Any operator in the stack having higher precendence than the current
// operator, will be popped and placed into the postfix expression and current
// operator will be pushed
// 4. So basically if the precendence of the incoming operator is higher than
// the one in stack then the incoming token will be pushed on to the stack
// 5. So if an element in the stack has something on top if it then it will be
// of greater precendence
// 6. When End of Expression is reached, pop everything
// 7. Anything inside paranthesis will be treated as a separate expression
// 8. if its an opening paranthesis it will be pushed onto the stack
// 9. no change in rule for operand it will be apended to the postfix part
// 10. now if an operator comes, look at top of stack if its an operator of
// higher precendence i can pop and then see the next top and once again if it
// of higher precendence i should pop again and i shud stop when an opening
// paranthesis comes and then push the operator itself
// 11. if a closing paranthesis comes, pop all operators till an opening
// paranthesis comes and append
// 12. after that pop that opening paranthesis also

#define MAX 20
typedef struct {
  char data[MAX];
  int top;

} STACK;

void initialiseStack(STACK *stack);

void push(STACK *stack, char element); // add to stack

char pop(STACK *stack); // pop the top of stack

char peek(STACK *stack); // get the current top element

void InfixToPostfix(char *expression, char *postfix);

int HasHigherPrecedence(char operator1, char operator2);

int isEmpty(STACK *stack) { // returns 1 if empty // 0 if false
  if (stack->top == -1) {
    return 1;
  }
  return 0;
}

int IsOperator(char C) {
  return (C == '+' || C == '-' || C == '/' || C == '%');
}

int IsOperand(char C) {
  return ((C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z') ||
          (C >= '0' && C <= '9'));
}

int main() {
  STACK S;
  char expression[MAX];
  char postfix[MAX];

  initialiseStack(&S);

  printf("Enter Infix Expression:\n");
  fgets(expression, sizeof(expression), stdin);
  expression[strlen(expression) - 1] = '\0'; // Remove the newline character

  InfixToPostfix(expression, postfix);

  printf("Output = %s\n", postfix);

  return 0;
}

void initialiseStack(STACK *stack) { stack->top = -1; }

void push(STACK *stack, char element) {
  if (stack->top < MAX - 1) {
    stack->top++;
    stack->data[stack->top] = element;
  }
}

char pop(STACK *stack) {
  if (isEmpty(stack) == 0) {
    char popped = stack->data[stack->top];
    stack->top--;
    return popped;
  }
  return '\0'; // return null character if stack is empty
}

int HasHigherPrecedence(char operator1, char operator2) {
  int op1Weight, op2Weight;

  // Assign weights based on precedence (modify as needed)
  switch (operator1) {
  case '+':
  case '-':
    op1Weight = 1;
    break;
  case '*':
  case '/':
  case '%':
    op1Weight = 2;
    break;
  case '$':
    op1Weight = 3;
    break;
  default:
    op1Weight = 0;
  }

  switch (operator2) {
  case '+':
  case '-':
    op2Weight = 1;
    break;
  case '*':
  case '/':
  case '%':
    op2Weight = 2;
    break;

  default:
    op2Weight = 0;
  }

  // Compare weights to determine precedence
  return op1Weight >= op2Weight;
}

void InfixToPostfix(char *expression, char *postfix) {
  STACK S;
  initialiseStack(&S);

  int i, j;
  for (i = 0; expression[i] != '\0'; i++) {
    if (expression[i] == ' ' || expression[i] == ',') {
      continue;
    } else if (IsOperand(expression[i])) { // if operand put to postfix
      postfix += expression[i];
    } else if (IsOperator(expression[i])) {
      // if top of stack has higher precendence than the current operator
      // then append the top of stack to the result
      // we have to pop until opening paranthesis is reached so stop when we get
      // an opening paranthesis
      while (!isEmpty(&S) && peek(&S) != '(' &&
             HasHigherPrecedence(peek(&S), expression[i])) {
        postfix += peek(&S); // add top of stack to postfix
        pop(&S);             // pop the top of stack
      }
      push(&S,
           expression[i]); // push current operator after all the operators in
                           // stack with higher precendence have been popped
    } else if (expression[i] == '(') { // opening paranthesis, push it to stack
      push(&S, expression[i]);
    } else if (expression[i] ==
               ')') { // if closing paranthesis, pop everything until opening
                      // paranthesis and add it to postfix. after that pop
                      // opening paranthesis too to mark end of that particular
                      // expression
      while (!isEmpty(&S) && peek(&S) != '(') {
        postfix += peek(&S);
        pop(&S);
      }
      pop(&S); // pop the opening paranthesis
    }

    // for the operators left in the stack
    while (!isEmpty(&S)) {
      postfix += peek(&S);
      pop(&S);
    }

    // return postfix expression
  }
}
