/*
File: stack.c

Author: Doyeon Ryu
Date: 2024.01.24
Course: data structure-StacknQueue

Summary of file:
    Create a new array of integer variables by using dinamic memory allocation and create a stack.
    Each variables are randomly allocated.
    Push all variables and print the stack.
    Pop all variables and free them.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int *nums;
    int top;
} Stack;

void initStack(Stack* , int );
int stackFull(Stack* , int );
int stackEmpty(Stack* );
void push(Stack* , int , int );
int pop(Stack* , int );
void printStack(Stack* , int );
void freeStack(Stack* );

int main()
{
    int myStackSize, val;
    srand(time(NULL));

    printf("My stack size is: ");
    scanf("%d", &myStackSize);

    Stack* myStack;
    initStack(myStack, myStackSize); //Create a stack

    printf("Nums: ");
    for (int i = 0; i < myStackSize; i++) {
        myStack->nums[i] = rand() % 101;
        printf("%d ", myStack->nums[i]);
    }
    printf("\n--------------------\n");

    //Push
    for (int i = 0; i < myStackSize; i++) {
        val = myStack->nums[i];
        printf("Push: %d\n", val);
        push(myStack, myStackSize, val);
    }
    printf("\n--------------------\n");
    printStack(myStack, myStackSize);
    printf("\n--------------------\n");

    //Pop
    while(!stackEmpty(myStack)) {
        val = pop(myStack, myStackSize);
        printf("Popped: %d\n", val);
    }
    printf("\n--------------------\n");
    printf("My stack is empty.\n");

    //Free the stack
    freeStack(myStack);

    return 0;
}

/*
void initStack(Stack* stack, int stackSize) 

Summary of the function:
    The function contains code that creates a new stack by dynamic memory allocation.

Parameters: Stack* stack, int stackSize

Return value:
    if fail to allocation, return
    else Nothing

Description:
    Create a new stack by dynamic memory allocation.
*/
void initStack(Stack* stack, int stackSize)
{
    stack->nums = (int *) malloc (stackSize * sizeof(int));
    stack->top = -1;

    // Defensive coding
    if (stack->nums == NULL) {
        printf("Memory is full\n");
        return;
    }
}

/*
int stackFull(Stack* stack, int stackSize) 

Summary of the function:
    The function contains code that checks the stack is full.

Parameters: Stack* stack, int stackSize

Return value:
    if stack is full, return 1
    else return 0

Description:
    if stack's top + 1 equals stack size, stack is full and return 1
    else, stack is not full and return 0
*/
int stackFull(Stack* stack, int stackSize)
{
    if ((stack->top +1) == stackSize)
        return 1;
    else
        return 0;
}

/*
int stackEmpty(Stack* stack)  

Summary of the function:
    The function contains code that checks the stack is empty.

Parameters: Stack* stack

Return value:
    if stack is empty, return 1
    else return 0

Description:
    if stack's top is -1, stack is empty and return 1
    else, stack is not empty and return 0
*/
int stackEmpty(Stack* stack) 
{
    if(stack->top == -1)
        return 1;
    else
        return 0;
}

/*
void push(Stack* stack, int stackSize, int value) 

Summary of the function:
    The function contains code that pushs in the stack.

Parameters: Stack* stack, int stackSize, int value(to push in the stack)

Return value: Nothing

Description:
    If stack isn't full, top add 1 and push the value in the stack
*/
void push(Stack* stack, int stackSize, int value)
{
    if (stackFull(stack, stackSize)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    else {
        stack->nums[++stack->top] = value;
    }
}

/*
int pop(Stack* stack, int stackSize)

Summary of the function:
    The function contains code that pops in the stack.

Parameters: Stack* stack, int stackSize

Return value: 
    If stack is empty, return -1
    else return stack->nums[stack->top--]

Description:
    If stack isn't empty, stack's top substract 1
*/
int pop(Stack* stack, int stackSize)
{
    if (stackEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->nums[stack->top--];
}

/*
void printStack(Stack* stack, int stackSize)

Summary of the function:
    The function contains code that prints stack.

Parameters: Stack* stack, int stackSize

Return value: 
    Nothing

Description:
    It scans all stack's nums and print them.
*/
void printStack(Stack* stack, int stackSize)
{
    printf("Print Stack: ");
    for (int i = 0; i < stackSize; i++) {
        printf("%d ", stack->nums[i]);
    }
    printf("\n");
}

/*
void freeStack(Stack* stack)

Summary of the function:
    The function contains code that frees stack

Parameters: Stack* stack

Return value: 
    Nothing

Description:
    It free all stack's nums.
*/
void freeStack(Stack* stack) 
{
    free(stack->nums);
    printf("Free all stack nums.\n");
}
