#include <stdio.h>
#define SIZE 100

struct array
{
    int n;
    int arr[SIZE];
} a;

void insertion()
{
    int x;
    printf("Enter value: ");
    scanf("%D", &x);
    if (a.n < SIZE - 1)
    {
        a.n = a.n + 1;
        a.arr[a.n] = x;
    }
    else
    {
        printf("\n-----No more space!-----\n");
    }
}

int linearSearch(int x)
{
    for (int i = 0; i < a.n; i++)
    {
        if (a.arr[i] == x)
            return i;
    }
    return -1;
}

int binarySearch(int x)
{
    int l = 0;
    int r = a.n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a.arr[m] == x)
            return m;
        else if (a.arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

void deletion()
{
    int x;
    printf("What value do you want to delete: ");
    scanf("%d", &x);
    int n = binarySearch(x);
    if (n != -1)
    {
        a.n = a.n - 1;
        for (int i = n; i < a.n; i++)
        {
            a.arr[i] = a.arr[i + 1];
        }
    }
    else
        printf("\n-----Value not found!-----\n");
    return;
}

void traverse()
{
    for (int i = 0; i <= a.n; i++)
    {
        printf("%d ", a.arr[i]);
    }
    printf("\n");
}

int main()
{
    a.n = -1;
    int x;
    int b;
    int ch = 1;
    while (ch != 0)
    {
        printf("What operation would you like to perform?\n");
        printf("1.Insert a value\n");
        printf("2.Delete a value\n");
        printf("3.Linear Search a value\n");
        printf("4.Binary Search a value\n");
        printf("5.Traverse all the values\n");
        printf("0.Exit: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            printf("Enter value you want to find: ");
            scanf("%d", &x);
            b = linearSearch(x);
            printf("\nThe value was found at %d index\n", b);
            break;
        case 4:
            printf("Enter value you want to find: ");
            scanf("%d", &x);
            b = binarySearch(x);
            printf("\nThe value was found at %d index\n", b);
            break;
        case 5:
            traverse();
            break;
        case 0:
            printf("\nExit");
            break;
        default:
            printf("\n-----Invalid choice!-----\n");
            break;
        }
    }

    return 0;
}