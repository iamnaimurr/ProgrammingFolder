#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[][3] = {
        {50, 1, 2},
        {30, 3, 4},
        {70, 5, 6},
        {20, 7, -1},
        {40, -1, -1},
        {60, -1, -1},
        {70, -1, -1},
        {10, -1, -1}};
    printf("-------| Pre-order Traversal    |-------\n\n");
    int stack[100];
    int top = -1;
    int i = 0;
    printf("[ ");
    while (i != -1 || top != -1)
    {
        printf("%d ", t[i][0]);
        if (t[i][2] != -1)
            stack[++top] = t[i][2];
        i = t[i][1] != -1 ? t[i][1] : (top != -1 ? stack[top--] : -1);
    }
    printf("]\n\n\n");
    printf("\n-------| In-order Traversal |-------\n\n");
    top = -1;
    i = 0;
    printf("[ ");
    while (i != -1 || top != -1)
    {
        while (i != -1)
        {
            stack[++top] = i;
            i = t[i][1];
        }
        i = stack[top--];
        printf("%d ", t[i][0]);
        i = t[i][2];
    }
    printf("]\n\n\n");
    printf("\n------| Post-order Traversal |------\n\n");
    top = -1;
    i = 0;
    printf("[ ");
    int pi = -1;
    while (i != -1 || top != -1)
    {
        while (i != -1)
        {
            stack[++top] = i;
            i = t[i][1];
        }
        i = stack[top];
        if (t[i][2] != -1 && t[i][2] != pi)
            i = t[i][2];
        else
        {
            printf("%d ", t[i][0]);
            pi = i;
            top--;
            i = -1;
        }
    }
    printf("]\n\n\n");
    return 0;
}