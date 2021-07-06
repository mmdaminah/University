#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int rear, front, size, capacity;
    int* array, *priority;
};
void enqueue(struct Queue* queue, int item, int prio){
    if(queue->size == queue->capacity)
        printf("Queue is Full!!!\n");
    else{
        queue->rear++;
        queue->array[queue->rear] = item;
        queue->priority[queue->rear] = prio;
        queue->size++;
        printf("%d with priority %d added!!!\n", item, prio);
    }
}
int main(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = 4;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    queue->priority = (int*)malloc(queue->capacity*sizeof(int));
    enqueue(queue, 1, 1);
    enqueue(queue, 2, 2);
    enqueue(queue, 3, 3);
    enqueue(queue, 4, 4);
    enqueue(queue, 5, 5);

    return 0;
}