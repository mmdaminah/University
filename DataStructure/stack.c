#include <stdio.h>
#include <stdlib.h>
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
} 
int isEmpty(struct Stack* stack){
    if(stack->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct Stack* stack){
    if(stack->top == stack->capacity - 1)
        return 1;
    else
        return 0;
}
void push(struct Stack* stack, int item){
    if(isFull(stack) == 1 )
        printf("Stack is Full!!!\n");
    else{
        stack->top = stack->top + 1;
        stack->array[stack->top] = item;
        printf("%d pushed to stack\n", item);
    }
}
int pop(struct Stack* stack){
    if(isEmpty(stack) == 1 )
        printf("Stack is Empty!!!\n");
    else{
        int item = stack->array[stack->top];
        stack->top = stack->top - 1;
        return item;
    }
}
int peek(struct Stack* stack){
    if(isEmpty(stack) == 1 )
        printf("Stack is Empty!!!\n");
    else
        return stack->array[stack->top];
}
int main(){
    struct Stack* stack = createStack(100); 
  
    push(stack, 10); 
    push(stack, 20); 
    push(stack, 30); 
  
    printf("%d popped from stack\n", pop(stack)); 
  
    return 0;
}