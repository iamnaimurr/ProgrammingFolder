#include <stdio.h>

int arr[20] = {57, 88, 12, 97, 34, 61, 45, 23, 55, 70, 39, 46, 94};

void DELETE(int position)
{
    --position;
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = position; i < length - 1; i++)
        arr[i] = arr[i + 1];
    arr[length - 1] = 0; // Optional: Clear the last element
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
    printf("---------------------| DELETE |---------------------\n\n");
    int position;
    display();
    printf("Position >>> ");
    scanf("%d", &position);
    DELETE(position);
    display();
    return 0;
}

