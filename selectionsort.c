#include <stdio.h>
#define N 10
void selectionSort(int arr[N])
{
    int i, j, temp, min;
    for (i = 0; i < N - 1; i++)
    {
        min = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[N] = {20,4,7,21,17,1,6};
    printf("Before Sorting: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    selectionSort(arr);
    printf("\nAfter Sorting: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

