#include <stdio.h>

int arr[20] = {57, 88, 12, 97, 34, 61, 45, 23, 55, 70, 39, 46, 94};

void INSERT(int position, int val)
{
    --position;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = length; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = val;
}

void display()
{
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    printf("---------------------| INSERT |---------------------\n\n");
    int position, val;
    display();
    printf("Position >>> ");
    scanf("%d", &position);
    printf("Value >>> ");
    scanf("%d", &val);
    INSERT(position, val);
    display();
    return 0;
}

