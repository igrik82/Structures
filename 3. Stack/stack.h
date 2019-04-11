#ifndef INC_3__STACK_STACK_H
#define INC_3__STACK_STACK_H

struct stack
{
    int data;
    struct stack *next;
};

//Print list
void printList(struct stack *List);
//Push data to stack
struct stack *pushToStack(int data, struct stack *List);
//Pop data from stack
struct stack *popFromStack(struct stack *List);
//Free memory
void freeMemory(struct stack *List);

#endif //INC_3__STACK_STACK_H
