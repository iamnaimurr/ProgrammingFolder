#include <stdio.h>
#define MAX 5
int STACK[MAX], top = -1;
void PUSH()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow ! Cannot push more elements.\n");
    }
    else
    {
        int value;
        printf("Enter the value to PUSH >>> ");
        scanf("%d", &value);
        STACK[++top] = value;
        printf("Pushed [ %d ] onto the stack.\n", value);
    }
}
void POP()
{
    if (top == -1)
    {
        printf("Stack Underflow ! The Stack is EMPTY.\n");
    }
    else
    {
        printf("Popped [ %d ] from the stack.\n", STACK[top--]);
    }
}
void SHOW()
{
    if (top == -1)
    {
        printf("The Stack is EMPTY !\n");
    }
    else
    {
        printf("Stack [ ");
        for (int i = top; i >= 0; --i)
        {
            printf("%d ", STACK[i]);
        }
        printf("]\n");
    }
}
void DISPLAY()
{
    system("clear");
    printf("----------------------------| STACK |----------------------------\n\n");
    printf("--> (1) PUSH\n");
    printf("--> (2) POP\n");
    printf("--> (3) SHOW\n");
    printf("--> (4) EXIT\n");
}
int main()
{
    int choice;
    DISPLAY();
    while (1)
    {
        printf("\nEnter Your Choice -----------------------> ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            SHOW();
            break;
        case 4:
            printf("-----------------------------| EXIT |--------------------------- -\n\n ");
            return 0;
        default:
            printf("Invalid choice ! Please try again.\n");
        }
    }
    return 0;
}