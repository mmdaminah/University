#include <stdio.h>
#include <stdlib.h>
int hash_function(int key, int size){
    return key%size;
}
struct hash_table_item{
    int key;
    char data;
};
struct hash_table{
    struct hash_table_item* items;
    int size;
    int capacity;
};
void insert(struct hash_table* table, int key, char data){
    int index = hash_function(key,table->size);
    if(table->capacity == 0)
        printf("table is full!!!\n");
    else if(table->items[index].key == -1){
        table->items[index].key = key;
        table->items[index].data = data;
        table->capacity--;
    }
    else{
        while(table->items[index++].key != -1);
        table->items[index-1].key = key;
        table->items[index-1].data = data;
        table->capacity--;
    }
}
int main(){
    int i;
    struct hash_table *table;
    int key[]={10, 23, 53, 21, 65};
    char data[]={'A', 'B', 'C', 'D', 'E'};
    table->size = sizeof(key)/sizeof(key[0]);
    table->capacity = 5;
    table->items = (struct hash_table_item*)malloc(table->size*sizeof(struct hash_table_item));
    for(i=0;i<table->size;i++){
        table->items[i].key = -1;
        table->items[i].data = -1;
    }
    for(i=0;i<table->size;i++)
        insert(table, key[i], data[i]);
    for(i=0;i<table->size;i++)
        printf("%c\n", table->items[i].data);
    return 0;
}