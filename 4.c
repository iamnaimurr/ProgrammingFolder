#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int target)
{
    int Beg = 0, End = n - 1;
    while (Beg <= End)
    {
        int Mid = Beg + (End - Beg) / 2;
        if (arr[Mid] == target)
            return Mid;
        if (arr[Mid] < target)
            Beg = Mid + 1;
        else
            End = Mid - 1;
    }
    return -1;
}

int main()
{
    printf("\n-----------------| Binary Search |-----------------");
    printf("\n\nEnter Array SIZE = ");
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    printf("\nEnter All The Elements = ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("\nSorted Array: [ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
    
    int target;
    printf("\nEnter the element to search: ");
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1)
        printf("\nElement %d found at index %d.\n", target, result);
    else
        printf("\nElement %d not found in the array.\n", target);
    
    free(arr);
    return 0;
}

