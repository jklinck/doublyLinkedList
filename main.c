//  gcc -o main main.c doublyLinkedList.c

#include <stdio.h>
#include "doublyLinkedList.h"

int main()
{
    add(3);
    add(5);
    add(7);
    add(9);
    add(11);
    
    // print();
    
    printf("%d\n", list->next->next->next->next->prev->data);
    clear();

    return 0;
}







