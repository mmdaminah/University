#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
};
struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = -1;
    queue->array = (int*)malloc( queue->capacity * sizeof(int));
}
int isFull(struct Queue* queue){
    if(queue->size == queue->capacity)
        return 1;
    else
        return 0;   
}
int isEmpty(struct Queue* queue){
    if(queue->size == 0)
        return 1;
    else
        return 0;
}
void enQueue(struct Queue* queue, int item){
    if(isFull(queue) == 1)
        printf("Queue is full!!!\n");
    else{
        queue->rear = (queue->rear+1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size = queue->size +1;
        printf("%d added to the queue.\n", item);
    }    
}
int deQueue(struct Queue* queue){
    if(isEmpty(queue) == 1)
        printf("queue is Empty!!!\n");
    else{
        int item = queue->array[queue->front];
        queue->front = (queue->front+1) % queue->capacity;
        queue->size = queue->size - 1;
        return item;
    }
}
int front(struct Queue* queue){
    if(isEmpty(queue)==1)
        printf("queue is Empty!!!\n");
    else
        return queue->array[queue->front];
}
int rear(struct Queue* queue){
    if(isEmpty(queue)==1)
        printf("queue is Empty!!!\n");
    else
        return queue->array[queue->rear];
}
int main(){
    struct Queue* queue = createQueue(2);

    rear(queue);
    front(queue);
    enQueue(queue, 1);
    enQueue(queue, 2);
    
    return 0;
}