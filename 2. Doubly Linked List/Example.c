#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublyLinkedList.h"

int main() {
    struct doublyLinkedList *List = NULL;

    char string1[] = "Hello, world";
    int strLength = strlen(string1);

    // Adding each character as end node
    for(size_t i = 0; i < strLength; ++i){
        List = addNodeAtEnd(string1[i], List);
    }
    printList(List);
    puts("");

    //Add node(new character) after a given node(existing character)
    List = addNodeAfter('r', '#', List);
    printList(List);
    puts("");

    //Delete first equal character
    List = deleteCharacter(',', List);
    printList(List);
    puts("");

    puts("\n");
    freeMemory(List);
    List = NULL;


    char string2[] = "Polly want a cracker";
    strLength = strlen(string2);

    //Adding each character as front node
    for(size_t i = 0; i < strLength; ++i){
        List = addNodeAtFront(string2[i], List);
    }
    printList(List);
    puts("");

    //Add node(new character) after a given node(existing character)
    List = addNodeAfter('r', '#', List);
    printList(List);
    puts("");

    //Delete first equal character
    List = deleteCharacter('P', List);
    printList(List);
    puts("");

    freeMemory(List);
    List = NULL;

}