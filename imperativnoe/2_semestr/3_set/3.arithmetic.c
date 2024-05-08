#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_CAPACITY 1000

// Структура для стека
struct Stack {
  char** items;
  int top;
  int capacity;
};

// Функция для создания стека
struct Stack* createStack() {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (!stack) {
    printf("Ошибка: не удалось выделить память для стека.\n");
    exit(EXIT_FAILURE);
  }
  stack->capacity = STACK_CAPACITY;
  stack->top = -1;
  stack->items = (char**)malloc(stack->capacity * sizeof(char*));
  if (!stack->items) {
    printf("Ошибка: не удалось выделить память для элементов стека.\n");
    exit(EXIT_FAILURE);
  }
  return stack;
}

// Функция для освобождения памяти, выделенной под элементы стека
void freeStack(struct Stack* stack) {
  for (int i = 0; i <= stack->top; i++) {
    free(stack->items[i]);
  }
  free(stack->items);
  free(stack);
}

// Функция для проверки, пуст ли стек
int isEmpty(struct Stack* stack) { return stack->top == -1; }

// Функция для добавления элемента в стек
void push(struct Stack* stack, char* item) {
  stack->items[++stack->top] = item;
}

// Функция для удаления элемента из стека
char* pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Ошибка: попытка удаления элемента из пустого стека.\n");
    exit(EXIT_FAILURE);
  }
  return stack->items[stack->top--];
}

// Функция для получения верхнего элемента стека без его удаления
char* peek(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Ошибка: попытка доступа к верхнему элементу пустого стека.\n");
    exit(EXIT_FAILURE);
  }
  return stack->items[stack->top];
}

// Функция для определения приоритета оператора
int precedence(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

// Функция для преобразования инфиксного выражения в обратную польскую запись
char* infixToPostfix(char* expression) {
  struct Stack* stack = createStack();
  char* postfix = (char*)malloc(strlen(expression) * sizeof(char));
  int i, k = 0;

  for (i = 0; expression[i]; i++) {
    if (isspace(expression[i])) {
      continue;
    } else if (isdigit(expression[i]) ||
               (expression[i] == '-' && isdigit(expression[i + 1]))) {
      while (isdigit(expression[i]) || expression[i] == '.') {
        postfix[k++] = expression[i++];
      }
      postfix[k++] = ' ';
      i--;
    } else if (expression[i] == '(') {
      push(stack, "(");
    } else if (expression[i] == ')') {
      while (!isEmpty(stack) && strcmp(peek(stack), "(")) {
        postfix[k++] = *pop(stack);
        postfix[k++] = ' ';
      }
      pop(stack);  // Удаление "(" из стека
    } else {
      while (!isEmpty(stack) &&
             precedence(*peek(stack)) >= precedence(expression[i])) {
        postfix[k++] = *pop(stack);
        postfix[k++] = ' ';
      }
      push(stack, (char[]){expression[i], '\0'});
    }
  }

  while (!isEmpty(stack)) {
    postfix[k++] = *pop(stack);
    postfix[k++] = ' ';
  }

  postfix[--k] = '\0';  // Удаляем последний лишний пробел
  freeStack(stack);
  return postfix;
}

// Функция для вычисления значения выражения в обратной польской записи
double evaluatePostfix(char* expression) {
  struct Stack* stack = createStack();
  char *token, *endptr;
  double operand1, operand2, result;

  token = strtok(expression, " ");
  while (token != NULL) {
    if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) {
      push(stack, token);
    } else {
      operand2 = strtod(pop(stack), &endptr);
      operand1 = strtod(pop(stack), &endptr);
      switch (*token) {
        case '+':
          push(stack, (char*)malloc(20 * sizeof(char)));
          sprintf(peek(stack), "%.10f", operand1 + operand2);
          break;
        case '-':
          push(stack, (char*)malloc(20 * sizeof(char)));
          sprintf(peek(stack), "%.10f", operand1 - operand2);
          break;
        case '*':
          push(stack, (char*)malloc(20 * sizeof(char)));
          sprintf(peek(stack), "%.10f", operand1 * operand2);
          break;
        case '/':
          push(stack, (char*)malloc(20 * sizeof(char)));
          sprintf(peek(stack), "%.10f", operand1 / operand2);
          break;
        default:
          // Обработка некорректного входного выражения
          break;
      }
    }
    token = strtok(NULL, " ");
  }
  result = strtod(pop(stack), &endptr);
  freeStack(stack);
  return result;
}

int main() {
  char input_expression[] = "-5+ 4 *7- 3* 2 + 17/3- 5 + (3 - 5 + 3) * 2";
  char* postfix_expression = infixToPostfix(input_expression);
  double result = evaluatePostfix(postfix_expression);
  printf("%.20f\n", result);
  free(postfix_expression);
  return 0;
}
