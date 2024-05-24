#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

// add a node to the list
void add(struct ll** head, int nodeData){
    struct ll* newNode = malloc(sizeof(struct ll));
    if(newNode == NULL){
        printf("Memory allocation for newNode inside of add function failed!\n");
        return;
    }
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
        printf("This list is empty!\n");
        return;
    }
    
    struct ll* temp = head;
    printf("[");
    while(temp != NULL){
        // prints closing bracket after tail
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
    // set head to NULL to prevent memory leak
    *head = NULL;
}

// remove a node
void removeNode(struct ll** head, int nodeData){
    // check if list is empty
    if(*head == NULL){
        printf("The list is empty, so you cannot remove that node.\n");
        return;
    }
    struct ll* current = *head;

    // removes head, head->next becomes new head
    if((*head)->data == nodeData){
        // removing nodeData in a single node list
        if((*head)->next == NULL){
            free(*head);
            *head = NULL;
            return;
        }
        (*head)->next->prev = NULL;
        *head = (*head)->next;
        free(current);
        return;
    }

    // iterates through list looking for nodeData
    while(current->data != nodeData){    
        current = current->next;
        // check for nodeData not being present in list
        if(current == NULL){
            printf("That node does not exist in this list.\n");
            return;
        }
    }

    // removes tail
    if(current->next == NULL){
        current->prev->next = NULL;
        free(current);
        return;
    }

    // removes nodeData when nodeData is not the head or tail
    current->next->prev = current->prev;
    current->prev->next = current->next;
    free(current);
}





