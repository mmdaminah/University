#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct listNode{
    struct treeNode* node;
    struct listNode* next;
};
//value:left ---> 0
//value:right ---> 1
struct treeNode{
    char letter;
    int frequency;
    int value;
    struct treeNode* parent;
    struct treeNode* right;
    struct treeNode* left;
};
void sort(struct listNode* head, int size){
    struct listNode* temp = head;
    struct listNode* nextTemp = NULL;
    for (int i = 0; i < size-1; i++){
        temp = head;
        for (int j = 0; j < size-i-1; j++){
            nextTemp = temp->next;
            if(temp->node->frequency > nextTemp->node->frequency){
                struct treeNode *tempNode = temp->node;
                temp->node = nextTemp->node;
                nextTemp->node = tempNode;
            }
            temp = temp->next;
        }
    }    
}
struct listNode* buildTree(struct listNode* head, int size){
    sort(head, size);
    //creating parent node
    struct treeNode *temp = (struct treeNode*)malloc(sizeof(struct treeNode));
    //adding parent(temp) node frequency
    temp->frequency = head->node->frequency + head->next->node->frequency;
    //defining value 0 --> means left child of parent(temp)
    head->node->value = 0;
    //parent(temp) left child addressing
    temp->left = head->node;
    //assigning parent
    head->node->parent = temp;
    //defining value 1 --> means right child of parent(temp)
    head->next->node->value = 1;
    //parent(temp) right child addressing
    temp->right = head->next->node;
    //deleting first node at linked list
    //assigning parent
    head->next->node->parent = temp;
    head = head->next;
    //asigning first node to temp
    head->node = temp;
    return head;
}
int main(int argc, char* argv[]){
    //including file
    FILE *file;
    file = fopen( argv[1], "r");
    if(!file){
        printf("file not found!!!");
        exit(1);
    }
    char line[100];
    int index = 0;
    int letterIndex = 0;
    int number = 0;
    char* letter;
    int* frequency;
    char inputNumber[100];
    while(fgets(line, sizeof(line), file)){
        if(index == 0){
            number = atoi(line);
            letter = (char*)malloc(number*sizeof(char));
            frequency = (int*)malloc(number*sizeof(int));
            index++;
        }
        else{
            letter[letterIndex++] = line[0];
            int num = 0; 
            num = atoi(line+2);
            frequency[letterIndex-1] = num;
        }
    }
    fclose(file);
    for(int i=0; i < number;i++)
        printf("%c\t%d\n", letter[i],frequency[i]);
    //end of including file
    // char letter[]= {'n','h','s', 'd', '.', 'i', 'v', 'g', 'l', 'o', 'e', 'a', 'r', '$', 't', 'm', 'p' };
    // int frequency[]= { 8,4,2,1,1,5,2,3,5,5,12,6,7,14,7,4,4 };
    int arrayLength = number;
    //sizeof(letter)/sizeof(letter[0]);
    int size = arrayLength;
    //creating tree nodes
    struct treeNode *nodes = (struct treeNode*)malloc(arrayLength*sizeof(struct treeNode));
    for(int i = 0; i < arrayLength; i++){
        nodes[i].letter = letter[i];
        nodes[i].frequency = frequency[i];
        nodes[i].parent = NULL;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    //creating linked list of nodes
    struct listNode* head = (struct listNode*)malloc(sizeof(struct listNode));
    struct listNode* temp = head;
    for(int i = 0; i < arrayLength; i++){
        temp->node = &nodes[i];
        temp->next = (struct listNode*)malloc(sizeof(struct listNode));
        temp = temp->next;
    }
    temp->next=NULL;
    //building tree
    for(int i = 0; i < size-1; i++){
        head = buildTree(head, arrayLength);
        arrayLength--;
    }
    //codeing from leaf to root
    int *array[size];
    int arrayLength2 = 0;
    struct treeNode* tempTreeNode;
    for(int i = 0; i < size ; i++){
        tempTreeNode = &nodes[i];
        //finding the length of the path
        while(tempTreeNode->parent!=NULL){
        arrayLength2++;
        tempTreeNode = tempTreeNode->parent;
        }
        //creating array with length of the path
        array[i] = (int *)malloc((arrayLength2+1)*sizeof(int));
        //saving the length of the path in the first column
        array[i][0] = arrayLength2;
        tempTreeNode = &nodes[i];
        //saving codes to array from bottom to top(reverse needed)
        for(int j = 1; j < arrayLength2+1;j++){
            array[i][j] = tempTreeNode->value;
            tempTreeNode = tempTreeNode->parent;
        }
        arrayLength2 = 0;
    }
    //reversing the numbers saved in array:
    //allocaring the reversed array
    int *reversedArray[size];
    for(int i = 0; i < size; i++)
        reversedArray[i] = (int *)malloc(array[i][0]*sizeof(int));
    //asigning the reversed array (just codes)
    for(int i = 0; i < size;i++)
        for(int j = 1;j <= array[i][0];j++)
            reversedArray[i][array[i][0]-j+1] = array[i][j];
    //assignig the reversed array row length at each row 0 index
    for(int i = 0; i < size;i++)
        reversedArray[i][0] = array[i][0];
    //printing the array
    for(int i = 0; i < size;i++){
        printf("%c ",letter[i]);
        for(int j = 1;j <= array[i][0];j++)
            printf("%d",reversedArray[i][j]);
        printf("\n");
    }
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    for(int i = 0; i < size;i++){
        fprintf(outputFile,"%c ",letter[i]);
        for(int j = 1;j <= array[i][0];j++)
            fprintf(outputFile,"%d",reversedArray[i][j]);
        fprintf(outputFile,"\n");
    }
    return 0;
}