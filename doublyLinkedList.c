#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

// add a node to the list
void add(struct ll** head, int nodeData){
    struct ll* newNode = malloc(sizeof(struct ll));
    newNode->prev = NULL;
    newNode->data = nodeData;
    newNode->next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    struct ll* temp = *head;        
    struct ll* previous = *head;
    while(temp->next != NULL){
        previous = temp;
        temp = temp->next;
    }
    
    temp->next = newNode;
    temp->next->prev = temp;
}

// print the list to look like an array
void print(struct ll* head){
    if(head == NULL){
        printf("This list is empty!");
        return;
    }
    
    struct ll* temp = head;
    printf("[");
    while(temp != NULL){
        if(temp->next == NULL){
            printf("%d]\n", temp->data);
            return;
        }
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

// free up allocated heap memory
void clear(struct ll** head){
    struct ll* current = *head;
    struct ll* temp;

    while(current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
}

// remove a node
void removeNode(struct ll** head, int nodeData){
    struct ll* current = *head;

    if((*head)->data == nodeData){
        (*head)->next->prev = NULL;
        (*head) = (*head)->next;
        free(current);
        return;
    }

    while(current->data != nodeData){
        current = current->next;
        if(current->next == NULL){
            printf("That node does not exist in this list.");
            return;
        }
    }

    current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
}





