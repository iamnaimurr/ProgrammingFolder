#include <stdio.h>

void print(int DATA[], int LINK[], int START)
{
    printf("List = [ ");
    while (LINK[START - 1] != -1)
    {
        printf("%d ", DATA[START - 1]);
        START = LINK[START - 1];
    }
    printf("]\n\n");
}

int main()
{
    int data[] = {45, 57, 98, 12, 76, 0, 10, 23, 0, 9};
    int link[] = {7, 10, 2, -1, 1, -1, 3, 4, 6, 8};

    int start = 5;
    int available = 9;

    print(data, link, start);

    int K;
    printf("Enter The Value For K = ");
    scanf("%d", &K);

    int array_size = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < array_size; i++)
    {
        if (data[i] != 0)
        {
            data[i] += K;
        }
    }

    printf("\nList Updated ...\n\n");

    print(data, link, start);

    return 0;
}

