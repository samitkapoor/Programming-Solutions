#include <stdio.h>

int main()
{

    int a[4][4] = {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int n = 4;

    // implementing warshall's algorithm to find transitive closure
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (j != i)
                for (int k = 0; k < n; k++)
                    if (k != i)
                        if (a[i][k] == 1 && a[j][i] == 1)
                            a[j][k] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}