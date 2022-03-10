#include <stdio.h>

void merge(int *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for (i = 0; i < n1; i++)
        L[i] = *(arr + i + l);
    for (j = 0; j < n2; j++)
        R[j] = *(arr + j + m + 1);

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            *(arr + k) = L[i];
            i++;
            k++;
        }
        else
        {
            *(arr + k) = R[j];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        *(arr + k) = L[i++];
        k++;
    }

    while (j < n2)
    {
        *(arr + k) = R[j++];
        k++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{

    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(&arr, 0, n - 1);

    printf("\n\nArray after sorting!\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}