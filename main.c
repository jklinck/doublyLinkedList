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

    removeNode(&list, 13);
    print(list);
    
    // free up allocated heap memory
    clear(&list);
    return 0;
}







