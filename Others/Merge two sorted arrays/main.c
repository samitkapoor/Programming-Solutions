// Merge two array in ascending order to form a third array sorted in ascending order

#include <stdio.h>

int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int b[7] = {12, 34, 56, 78, 87, 98, 102};
    int c[17];

    int i = 0, j = 0, k = 0;
    while (i < 10 && j < 7)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < 10)
    {
        c[k++] = a[i++];
    }

    while (j < 7)
    {
        c[k++] = b[j++];
    }

    printf("[");
    for (i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("]");

    return 0;
}