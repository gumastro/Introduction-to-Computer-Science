#define Stack_SIZE 50

typedef struct stack {
  long long array[Stack_SIZE];
  long long top;

} Stack;

void create_stack(Stack* s);

long long push(Stack* s, long long x);

long long is_empty(Stack* s);

long long pop(Stack* s, long long* x);

long long see_top(Stack *s, long long* error);

void empty(Stack* s);
