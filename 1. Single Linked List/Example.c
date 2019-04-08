#include <stdio.h>
#include <stdlib.h>
#include "Single_Linked_List.h"

int main() {

    struct singleLinkedList *Node = NULL;

    int values[] = { 5, 10, 4, 8, 3, 16, 6, 7, 12, 6 };
    int sizeArray = sizeof(values) / sizeof(int);

    //add variables to list without sorting (0)
    for(size_t i = 0; i < sizeArray; ++i){
        Node = addToList(values[i], Node, 0);
    }
    printList(Node);

    //delete from list
    Node = deleteFromList(4, Node);
    Node = deleteFromList(16, Node);
    printList(Node);

    free(Node);
    Node = NULL;



    //add variables to list with sorting (1)
    for(size_t i = 0; i < sizeArray; ++i){
        Node = addToList(values[i], Node, 1);
    }
    printList(Node);

    //delete from list
    Node = deleteFromList(5, Node);
    Node = deleteFromList(6, Node);
    printList(Node);

    free(Node);
    Node = NULL;

}