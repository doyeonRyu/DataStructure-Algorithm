#include <stdio.h>
#define MAX_STACK_SIZE  10 // Set stack's max size

int stack[MAX_STACK_SIZE] = {}; // create stack
int top = -1;

void push(int );
int pop();
int stack_full();
int stack_empty();

int main()
{
    int testArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int value;
    int length = sizeof(testArr) / sizeof(testArr[0]);

    printf("\n---------------\n");
    printf("Push Test\n");

    // Push test
    for (int i = 0; i < length; i++) {
        value = testArr[i];
        if (!stack_full()) { // defensive coding
            push(value);
            printf("Push: %d\n", value);
        }
        else   
            printf("This stack is already full, Failed to push %d\n", value);
    }

    printf("\n---------------\n");
    printf("Pop Test\n");
    //Pop test
    while(!stack_empty()) { // defensive coding
        value = pop();
        printf("Pop: %d\n", value);
    }
    
    printf("\nNow the stack is empty.\n");
    return 0;
}

// when this function is called, top is added one and value is added in stack.
void push(int val)
{
    stack[++top] = val;
}

// This function returns stack and top is subtracted one.
int pop()
{
    return stack[top--];
}

// If stack is full which means number of (top+1) is MAX_STACK_SIZE, return 1. If stack is not full, return 0.
int stack_full()
{
    if ((top + 1) == MAX_STACK_SIZE)
        return 1;
    else 
        return 0;
}

// If stack is empty which means number of top is -1, return 1. If stack is not empty, return 0.
int stack_empty()
{
    if (top == -1) 
        return 1;
    else
        return 0;
}
