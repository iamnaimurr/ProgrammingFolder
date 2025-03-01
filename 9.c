#include <stdio.h>
#define SIZE 5
int QUEUE[SIZE];
int FRONT = -1, REAR = -1;
void ENQUEUE()
{
    if ((REAR + 1) % SIZE == FRONT)
    {
        printf("Queue Overflow! Unable to add more elements.\n");
        return;
    }
    int value;
    printf("Enter the value to Enqueue >>> ");
    scanf("%d", &value);
    if (FRONT == -1)
    {
        FRONT = 0;
    }
    REAR = (REAR + 1) % SIZE;
    QUEUE[REAR] = value;
    printf("Enqueued [ %d ]\n", value);
}
void DEQUEUE()
{
    if (FRONT == -1)
    {
        printf("Queue Underflow! No elements to dequeue.\n");
        return;
    }
    printf("Dequeued [ %d ]\n", QUEUE[FRONT]);
    if (FRONT == REAR)
    {
        FRONT = REAR = -1;
    }
    else
    {
        FRONT = (FRONT + 1) % SIZE;
    }
}
void SHOW_QUEUE()
{
    if (FRONT == -1)
    {
        printf("Queue is Empty.\n");
        return;
    }
    printf("QUEUE = [ ");
    int i = FRONT;
    while (1)
    {
        printf("%d ", QUEUE[i]);
        if (i == REAR)
        {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("]\n");
}
void ADD_VALUE_K()
{
    if (FRONT == -1)
    {
        printf("Queue is Empty. No values to add.\n");
        return;
    }
    int K;
    printf("Enter the value K to add to each element >>> ");
    scanf("%d", &K);
    int i = FRONT;
    while (1)
    {
        QUEUE[i] += K;
        if (i == REAR)
        {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("Added %d to every element in the queue.\n", K);
}
void DISPLAY()
{
    printf("------------------| QUEUE |------------------\n\n");
    printf(">>> Size of the QUEUE is [ %d ]\n\n", SIZE);
    printf("\t(1) Enqueue\n");
    printf("\t(2) Dequeue\n");
    printf("\t(3) Show Queue\n");
    printf("\t(4) Add value K to every node\n");
    printf("\t(5) Exit\n");
}
int main()
{
    DISPLAY();
    while (1)
    {
        char choice;
        printf("\nEnter Your Choice ------------------------> ");
    for_invalid_choice:
        scanf(" %c", &choice);
        printf("\n");
        switch (choice)
        {
        case '1':
            ENQUEUE();
            break;
        case '2':
            DEQUEUE();
            break;
        case '3':
            SHOW_QUEUE();
            break;
        case '4':
            ADD_VALUE_K();
            break;
        case '5':
            printf("-------------------| EXIT |------------------\n\n");
            return 0;
        default:
            printf("Invalid Choice ! Please Choose 1 to 5 ----> ");
            goto for_invalid_choice;
        }
    }
    return 0;
}
