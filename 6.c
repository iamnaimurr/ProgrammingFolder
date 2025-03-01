#include <stdio.h>

int D[100] = {45, 57, 98, 12, 76, 0, 10, 23, 0, 9};
int L[100] = {7, 10, 2, -1, 1, -1, 3, 4, 6, 8};
int st = 5;
int av = 9;

int main()
{
    printf("List = [ ");
    int p = st;
    while (p != -1)
    {
        printf("%d ", D[p - 1]);
        p = L[p - 1];
    }
    printf("]\n");
    int newD, pos;
    printf("\nPosition = ");
    scanf("%d", &pos);
    printf("\nData = ");
    scanf("%d", &newD);
    if (av == -1)
    {
        printf("\nThere is No space available in this LIST\n");
        return 0;
    }
    int newI = av;
    av = L[av - 1];
    D[newI - 1] = newD;
    if (pos == -1)
    {
        L[newI - 1] = st;
        st = newI;
    }
    else
    {
        int c = st, prev = -1, cPos = 1;
        while (c != -1 && cPos < pos)
        {
            prev = c;
            c = L[c - 1];
            cPos++;
        }
        if (cPos == pos)
        {
            L[newI - 1] = c;
            if (prev != -1)
                L[prev - 1] = newI;
        }
        else
        {
            printf("\nInvalid position\n");
            return 0;
        }
    }
    printf("\nUpdated List = [ ");
    p = st;
    while (p != -1)
    {
        printf("%d ", D[p - 1]);
        p = L[p - 1];
    }
    printf("]\n");
    return 0;
}