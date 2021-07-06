#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    int index;
    struct Node* next; 
};
void addNode(struct Node** node, int number, int index){
    if(*node == NULL){
        *node = (struct Node*)malloc(sizeof(struct Node));
        (*node)->data = number;
        (*node)->index = index;
        (*node)->next = NULL;
    }
    else{
        struct Node* temp = *node;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        (temp->next)->data = number;
        (temp->next)->index = index;
    }
}
void deleteNode(struct Node* head, struct Node** node){
    struct Node* temp = head;
    while (temp->next != *node)
        temp = temp->next;
    temp->next = NULL;
    *node = temp;
}
void printList(struct Node* node){
    while (node->next != NULL){
        printf("Address->%d\tdata->%d\tindex->%d\tnext->%d\n", node, node->data, node->index, node->next);
        node = node->next;
    }
    printf("Address->%d\tdata->%d\tindex->%d\tnext->%d\n", node, node->data,node->index, node->next);
}
int findNumber(struct Node* node, int index){
    while (node->next != NULL){
        if(node->index == index)
            return node->data;
        node = node->next;
    }
    if(node->index == index)
            return node->data;
    else
        return -1;
}
struct Node* findAddress(struct Node* node, int index){
    while (node->next != NULL){
        if(node->index == index)
            return node;
        node = node->next;
    }
    if(node->index == index)
            return node;
    else
        return NULL;
}
int partition (struct Node* node, int low, int high)
{
    //int pivot = arr[high]; // pivot
    int pivot = findNumber(node, high);


    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (findNumber(node, j) < pivot)
        {
            i++; // increment index of smaller element
            swap(i, j, node);
        }
    }
    swap(i + 1, high, node);
    return (i + 1);
}
void swap(int indexA, int indexB, struct Node* node)
{
    struct Node* nodeA = findAddress(node, indexA);
    struct Node* nodeB = findAddress(node, indexB);
    int temp = nodeA->data;
    nodeA->data = nodeB->data;
    nodeB->data = temp;
}

void quickSort(struct Node* node, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(node, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(node, low, pi - 1);
        quickSort(node, pi + 1, high);
    }
}
 
void sortedList(struct Node* node){
    printf("[");
    while (node->next != NULL){
        printf("%d,", node->data);
        node = node->next;
    }
    printf("%d", node->data);
    printf("]\n");
}

int main(){
    int index = 0;
    int n;
    int i;
    int temp;
    scanf("%d", &n);
    if(n == 0)
        printf("[]\n");
    else{
        struct Node* head = NULL;
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            addNode(&head,temp, index++);
        }
        quickSort(head,0,index-1);
        sortedList(head);
    }
    return 0;
}