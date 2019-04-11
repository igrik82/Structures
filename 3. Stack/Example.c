#include <stdio.h>
#include "stack.h"

int main()
{
    struct stack *stackDataList = NULL;

    //prepare the data
    int dataVariables[] = { 1, 3, 2, 5, 34, 6, 4, 2 };
    int sizeArray = sizeof(dataVariables) / sizeof(int);

    //push data to stack
    for(size_t i = 0; i < sizeArray; ++i)
    {
        stackDataList = pushToStack(dataVariables[i], stackDataList);
    }

    puts("The stack is now:");
    printList(stackDataList);

    int dataFromStack;
    //Pop element
    puts("Pop element. The stack is now:");
    dataFromStack = popFromStack(&stackDataList);
    printList(stackDataList);
    printf("%s%d\n", "The data from stack is -> ", dataFromStack);

    //Pop element
    puts("Pop element. The stack is now:");
    dataFromStack = popFromStack(&stackDataList);
    printList(stackDataList);
    printf("%s%d\n", "The data from stack is -> ", dataFromStack);

    freeMemory(stackDataList);

}