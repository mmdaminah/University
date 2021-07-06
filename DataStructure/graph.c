#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next; 
};


struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node* *array;
};
struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (struct Node*)malloc(queue->capacity*sizeof(struct Node));
    return queue;
}
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}
void enqueue(struct Queue* queue, struct Node *item){
    if(isFull(queue))
        return;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size+1;
    printf("%d enqueed to queue\n", item);
}
struct Node* dequeue(struct Queue* queue){
    if(isEmpty(queue))
        return;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front +1)%queue->capacity;
    queue->size = queue->size -1;
    return item;
}




void addNode(struct Node** node, int number){
    if(*node == NULL){
        *node = (struct Node*)malloc(sizeof(struct Node));
        (*node)->data = number;
        (*node)->next = NULL;
        printf("%d added!!!\n", number);
    }
    else{
        (*node)->next = (struct Node*)malloc(sizeof(struct Node));
        ((*node)->next)->data = number;
        *node = (*node)->next;
        (*node)->next = NULL;
        printf("%d added!!!\n", number);
    }
}
void printList(struct Node* node){
    while (node->next != NULL){
        printf("Address->%d\tdata->%d\tnext->%d\n", node, node->data, node->next);
        node = node->next;
    }
    printf("Address->%d\tdata->%d\tnext->%d\n", node, node->data, node->next);
}
int main(){
    int vertices;
    int i, j;
    int data;
    int ans;
    struct Node* temp;
    printf("Number of vertices:\n");
    scanf("%d", &vertices);
    struct Node* vertice[vertices];
    for(i=0;i<vertices;i++){
        vertice[i] = NULL;
        printf("Enter data:\n");
        scanf("%d", &data);
        addNode(&vertice[i], data);
    }
    for(i=0;i<vertices;i++){
        temp = vertice[i];
        for(j=0;j<vertices;j++){
            printf("is vertice %d connected to vertice %d?\n", i, j);
            scanf("%d", &ans);
            if(ans==1)
                addNode(&temp, vertice[j]->data);
        }
    }
    for(i=0;i<vertices;i++)
        printList(vertice[i]);

    struct Queue* queue = createQueue(vertices);
    int visited[vertices];
    for(i=0;i<vertices;i++)
        visited[i] = 0;
    for(i=0;i<vertices;i++){
        enqueue(queue, vertice[i]);
        temp = dequeue(queue);
        if(visited[i]==0){
            for(j=0;temp!=NULL;j++){
            if(temp->data == vertice[j]->data){
                printf("%d visited\n", temp->data);
                visited[j] = 1;
                temp = temp->next;
                 }
            }
        }
        
    }
}