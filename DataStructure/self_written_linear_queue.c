#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int front, rear, capacity;
    int* array;
};
void enqueue(struct Queue* queue, int item){
    if(queue->rear == queue->capacity-1)
        printf("queue is Full!!!\n");
    else
    {
        queue->rear++;
        queue->array[queue->rear] = item;
        printf("%d added to the queue!!!\n", item);
    }
}
void dequeue(struct Queue* queue){
    if(queue->rear == -1)
        printf("queue is Empty!!!\n");
    else if(queue->front > queue->rear)
        printf("queue is Full!!!\n");
    else{
        printf("%d is dequeued!!!\n", queue->array[queue->front]);
        queue->front++;
    }
}
void emptyQueue(struct Queue* queue){
    queue-> front = 0;
    queue-> rear = -1;
}
int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue-> front = 0;
    queue-> rear = -1;
    queue-> capacity = 3;
    queue->array = (int*)malloc(queue-> capacity*sizeof(int));
    
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    

    return 0;
}