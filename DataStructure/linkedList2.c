#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next; 
};
void addNode(struct Node** node, int number){
    if(*node == NULL){
        *node = (struct Node*)malloc(sizeof(struct Node));
        (*node)->data = number;
        (*node)->next = NULL;
        printf("%d added!!!\n", number);
    }
    else{
        struct Node* temp = *node;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = (struct Node*)malloc(sizeof(struct Node));
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
        printf("Address->%d\tdata->%d\tnext->%d\n", node, node->data, node->next);
        node = node->next;
    }
    printf("Address->%d\tdata->%d\tnext->%d\n", node, node->data, node->next);
}
int main(){
    struct Node* head = NULL;
    addNode(&head,1);
    addNode(&head,2);
    addNode(&head,3);
    addNode(&head,4);
    printList(head);
    return 0;
}