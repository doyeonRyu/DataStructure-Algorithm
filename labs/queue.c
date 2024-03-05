#include <stdio.h>
#define MAX_QUEUE_SIZE 10 // Set queue's max size

int queue[MAX_QUEUE_SIZE] = {}; // create queue
int front = -1;
int rear = -1;

void enqueue(int );
int dequeue();
int queue_full();
int queue_empty();

int main()
{
    int testArr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int value;
    int length = sizeof(testArr) / sizeof(testArr[0]);

    printf("\n---------------\n");
    printf("Enqueue Test\n");

    // Enqueue test
    for (int i = 0; i < length; i++) { 
        value = testArr[i];
        if (!queue_full()) { // defensive coding
            enqueue(value);
            printf("Enqueue: %d\n", value);
        }
        else   
            printf("This queue is already full, Failed to enqueue %d\n", value);
    }

    printf("\n---------------\n");
    printf("Dequeue Test\n");
    // Dequeue test
    while(!queue_empty()) { // defensive coding
        value = dequeue();
        printf("Dequeue: %d\n", value);
    }
    
printf("\nNow the queue is empty.\n");
    return 0;
}

// when this function is called, rear is added one and value is added in queue.
void enqueue(int val)
{
    queue[++rear] = val;
}

// This function returns queue and front is added one.
int dequeue()
{
    return queue[++front];
}

// If queue is full which means number of (rear-front) is MAX_QUEUE_SIZE, return 1. If queue is not full, return 0.
int queue_full()
{
    if ((rear - front) == MAX_QUEUE_SIZE) 
        return 1;
    else    
        return 0;
}

// If queue is empty which means front and rear is the same, return 1, else return 0
int queue_empty()
{
    if (front == rear)
        return 1;
    else
        return 0;
}
