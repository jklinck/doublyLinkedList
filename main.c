//  gcc -o main main.c doublyLinkedList.c

#include <stdio.h>
#include "doublyLinkedList.h"

int main()
{
    printf("\nCreate a single node list and check if it removes correctly\n");
    struct ll* list1 = NULL;
    add(&list1, 3);
    print(list1);
    removeNode(&list1, 3);
    print(list1);
    clear(&list1);
    printf("\n");


    printf("Create a two node list and remove the head\n");
    struct ll* list2 = NULL;
    add(&list2, 3);
    add(&list2, 5);
    print(list2);
    removeNode(&list2, 3);
    print(list2);
    clear(&list2);
    printf("\n");

    printf("Create a two node list and remove the second node/tail\n");
    struct ll* list3 = NULL;
    add(&list3, 3);
    add(&list3, 5);
    print(list3);
    removeNode(&list3, 5);
    print(list3);
    clear(&list3);
    printf("\n");

    printf("Create a three node list and remove the middle node\n");
    struct ll* list4 = NULL;
    add(&list4, 3);
    add(&list4, 5);
    add(&list4, 7);
    print(list4);
    removeNode(&list4, 5);
    print(list4);
    clear(&list4);
    printf("\n");

    printf("Create a three node list and remove the last node/tail\n");
    struct ll* list5 = NULL;
    add(&list5, 3);
    add(&list5, 5);
    add(&list5, 7);
    print(list5);
    removeNode(&list5, 7);
    print(list5);
    clear(&list5);
    printf("\n");

    return 0;
}







