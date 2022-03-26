 #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define OPERATORS 7

  struct node {
        int data;
        struct node *next;
  };

  struct node *top = NULL;

  /* operators and its precedence */
  char precedence[OPERATORS][2] = { {'(', 0}, {'+', 1}, {'-', 1},
                             {'*', 2}, {'/', 2}, {'%', 2},
                             {')', 3}};

  /* creating node with the given data */
  struct node* createNode(int data) {
        struct node *ptr = (struct node *) malloc(sizeof (struct node));
        ptr->data = data;
        ptr->next = NULL;
  }

  /* Push the given data into the stack */
  void push(int data) {
        struct node *ptr = createNode(data);
        if (top == NULL) {
                top = ptr;
                return;
        }
        ptr->next = top;
        top = ptr;
  }

  /* pop top element from the stack */
  int pop() {
        struct node *ptr;
        int data;
        if (top == NULL)
                return -1;
        ptr = top;
        top = top->next;
        data = ptr->data;
        free (ptr);
        return (data);
  }

  /* get the index of the operator in precedence array */
  int getIndex(int data) {
        int i;
        for (i = 0; i < OPERATORS; i++) {
                if (data == precedence[i][0])
                        return i;
        }
  }

  /* API to do infix to postfix conversion */
  void infix2postfix(char infix[], char postfix[]) {
        int i, j = 0, data;
        int index1, index2;
        for (i = 0; i < strlen(infix); i++) {
                /* given input is operator or not */
                if (tolower(infix[i]) >= 'a' && tolower(infix[i] <= 'z'))
                        postfix[j++] = infix[i];
                else if (infix[i] == ')') {
                        /*
                         * Input is close brace.  So, pop all
                         * elements until we encounter open brace
                         */
                        data = pop();
                        while (data != '(' && data != -1) {
                                postfix[j++] = data;
                                data = pop();
                        }
                } else if (infix[i] == '(') {
                        /* open brace - push it into stack */
                        push(infix[i]);
                } else {
                        /*
                         * take top element from the stack to
                         * check for operator precedence, to know
                         * whether the top element is open brace etc.
                         */
                        data = pop();
                        if (data == -1) {
                                push(infix[i]);
                                continue;
                        } else if (data == '(') {
                                /*
                                 * if top element in stack is open brace,
                                 * then push both top(data) and current input
                                 * into the stack.
                                 */
                                push(data);
                                push(infix[i]);
                                continue;
                        }

                        index1 = getIndex(data);
                        index2 = getIndex(infix[i]);
                        while (precedence[index1][1] >= precedence[index2][1]) {
                                /*
                                 * if the operator in stack has higher precedence
                                 * than the input operator, then pop the stack
                                 * operator and place it in output buffer.
                                 */
                                postfix[j++] = data;
                                data = pop();
                                if (data == -1) {
                                        push(infix[i]);
                                        break;
                                } else if (data == '(') {
                                        push(data);
                                        push(infix[i]);
                                        data = -1;
                                        break;
                                }
                                index1 = getIndex(data);
                        }
                        if (data != -1) {
                                push(data);
                                push(infix[i]);
                        }

                }
        }

        /* After processing all inputs, pop all other elements from stack */
        while (1) {
                if ((data = pop()) == -1)
                        break;
                postfix[j++] = data;
        }
        postfix[j] = '\0';
  }

  int main () {
        char str[100], output[100];
        printf("Enter ur Expression:");
        fgets(str, 100, stdin);
        infix2postfix(str, output);
        printf("Ouput: %s", output);
        return 0;
  }

