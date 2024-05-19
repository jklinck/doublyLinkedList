#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

struct ll* list = NULL;

void add(int nodeData){
    struct ll* newNode = malloc(sizeof(struct ll));
    newNode->prev = NULL;
    newNode->data = nodeData;
    newNode->next = NULL;
    
    if(list == NULL){
        list = newNode;
        return;
    }
    
    struct ll* temp = list;        
    struct ll* previous = list;
    while(temp->next != NULL){
        previous = temp;
        temp = temp->next;
    }
    
    temp->next = newNode;
    temp->next->prev = temp;
}

void print(){
    if(list == NULL){
        printf("The list is empty!");
        return;
    }
    
    struct ll* temp = list;
    printf("[");
    while(temp != NULL){
        if(temp->next == NULL){
            printf("%d]", temp->data);
            return;
        }
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

void clear(){
    struct ll* current = list;
    struct ll* temp;

    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
}
