#include <stdio.h>

int partition(int *arr, int l, int r)
{
    int i = l - 1;
    int p = r;
    for (int j = l; j < r; j++)
    {
        if (*(arr + j) < *(arr + p))
        {
            i++;
            int temp = *(arr + j);
            *(arr + j) = *(arr + i);
            *(arr + i) = temp;
        }
    }
    int temp = *(arr + p);
    *(arr + p) = *(arr + i + 1);
    *(arr + i + 1) = temp;

    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quickSort(&a, 0, n - 1);

    printf("Array after sort!\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}