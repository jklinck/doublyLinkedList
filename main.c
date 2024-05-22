//  gcc -o main main.c doublyLinkedList.c

#include <stdio.h>
#include "doublyLinkedList.h"

int main()
{
    struct ll* list = NULL;
    add(&list, 3);
    add(&list, 5);
    add(&list, 7);
    add(&list, 9);
    add(&list, 11);
    add(&list, 13);
    
    print(list);
    
    // teest to check if prev is working correctly
    printf("3 = %d\n", list->next->prev->data);
    printf("5 = %d\n", list->next->next->prev->data);
    printf("7 = %d\n", list->next->next->next->prev->data);
    printf("9 = %d\n", list->next->next->next->next->prev->data);
    printf("11 = %d\n", list->next->next->next->next->next->prev->data);
    
    // free up allocated heap memory
    clear(&list);
    return 0;
}







