#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

//Delete character
struct doublyLinkedList *deleteCharacter(char character, struct doublyLinkedList *List){
    if(List == NULL){
        puts("The list is empty.");
    } else {
        struct doublyLinkedList *previous = NULL;
        struct doublyLinkedList *current = NULL;
        struct doublyLinkedList *temp = NULL;

        //if nodes in straight order
        if(List->prev == NULL){
            previous = List;
            current = List->next;
            while ((current != NULL) && (previous->character != character) && (current->character != character)){
                previous = current;
                current = current->next;
            }

            //Looking in which case character is equal
            if(previous->character == character){
                temp = previous;
                List = current;
                List->prev = NULL;

                free(temp);
                temp = NULL;
            }
            else if(current->character == character){
                temp = current;
                previous->next = current->next;

                free(temp);
                temp = NULL;
            } else {
                puts("The character not found.");
            }

        //if nodes in reverse order
        } else {
            previous = List;
            current = List->prev;
            while((current != NULL) && previous->character != character && current->character != character){
                previous = current;
                current = current->prev;
            }

            //Looking in which case character is equal
            if(previous->character == character){
                temp = previous;
                List = current;
                List->next = NULL;

                free(temp);
                temp = NULL;
            }
            else if (current->character == character) {
                temp = current;
                previous->prev = current->prev;

                free(temp);
                temp = NULL;
            } else {
                puts("The character not found.");
            }
        }
    }
    return List;
}

//Add node(new character) after a given node(existing character)
struct doublyLinkedList *addNodeAfter(char existCharacter, char newCharacter, struct doublyLinkedList *List){
    if(List == NULL){
        puts("The list is empty");
        return NULL;
    } else {
        struct doublyLinkedList *previous = NULL;
        struct doublyLinkedList *current = NULL;
        struct doublyLinkedList *new = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));

        new->character = newCharacter;
        new->prev = NULL;
        new->next = NULL;

        if(List->prev == NULL){
            previous = List;
            current = List->next;
            while ((current != NULL) && previous->character != existCharacter){
                previous = current;
                current = current->next;
            }

            if(previous->character == existCharacter){
                previous->next = new;
                new->prev = previous;

                new->next = current;
                //if current not NULL
                if(current)
                    current->prev = new;

            } else {
                puts("The character not found.");
            }

        } else {
            previous = List;
            current = List->prev;
            while ((current != NULL) && previous->character != existCharacter){
                previous = current;
                current = current->prev;
            }

            if(previous->character == existCharacter){
                previous->prev = new;
                new->next = previous;

                new->prev = current;
                if(current)
                    current->next = new;
            } else {
                puts("The character not found.");
            }

        }
    }
    return List;
}

//Add node at the front
struct doublyLinkedList *addNodeAtFront(char character, struct doublyLinkedList *List){
    if(List == NULL){
        List = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
        List->character = character;
        List->prev = NULL;
        List->next = NULL;
    } else {
        struct doublyLinkedList *previous = NULL;
        struct doublyLinkedList *current = NULL;
        struct doublyLinkedList *new = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));

        new->character = character;
        new->prev = NULL;
        new->next = NULL;
        previous = List;
        current = List->prev;

        while (current != NULL){
            previous = current;
            current = current->prev;
        }

        previous->prev = new;
        new->next = previous;
    }
    return List;
}

//Add node at the end
struct doublyLinkedList *addNodeAtEnd(char character, struct doublyLinkedList *List){
    if(List == NULL){
        List = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));
        List->character = character;
        List->prev = NULL;
        List->next = NULL;
    } else {
        struct doublyLinkedList *previous = NULL;
        struct doublyLinkedList *current = NULL;
        struct doublyLinkedList *new = (struct doublyLinkedList*)malloc(sizeof(struct doublyLinkedList));

        new->character = character;
        new->prev = NULL;
        new->next = NULL;
        previous = List;
        current = List->next;

        while (current != NULL){
            previous = current;
            current = current->next;
        }

        previous->next = new;
        new->prev = previous;
    }
    return List;
}

//Printing, in order from places first node
void printList(struct doublyLinkedList *List){
    if(List == NULL){
        puts("The list is empty");
    } else {

        if(List->prev == NULL){
            puts("Moving in order NODE->NODE-> ... ->NULL:");
            while (List){
                printf("%c -> ", List->character);
                List = List->next;
            }
            puts("NULL");
        } else {
            puts("Moving in order NULL<- ... <-NODE<-NODE:");
            while (List){
                printf("%c -> ", List->character);
                List = List->prev;
            }
            puts("NULL");
        }
    }
}