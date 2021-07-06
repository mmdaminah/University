#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int front, rear, size, capacity;
    int* array;
};
void enqueue(struct Queue* queue, int item){
    if(queue->size == queue->capacity)
        printf("Queue is Full!!!\n");
    else{
        queue->rear = (queue->rear+1)% queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
        printf("%d added to queue!!!\n", item);
    }
}
void dequeue(struct Queue* queue){
    if(queue->size == 0)
        printf("Queue is Empty!!!\n");
    else{
        printf("%d dequeued!!!\n", queue->array[queue->front]);
        queue->front = (queue->front+1)% queue->capacity;
        queue->size--;
    }
}
int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->size = 0;
    queue->capacity = 3;
    queue->rear = queue->capacity - 1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
}