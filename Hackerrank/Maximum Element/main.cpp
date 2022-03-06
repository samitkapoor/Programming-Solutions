#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> stackk;
    int top = -1;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int op, x = 0;
        scanf("%d", &op);

        if (op == 1)
        {
            scanf("%d", &x);
            stackk.push_back(x);
            top++;
        }
        else if (op == 2)
        {
            stackk.pop_back();
            top--;
        }
        else
        {
            int max = INT_MIN;
            for (int i = 0; i < stackk.size(); i++)
            {
                if (max < stackk[i])
                {
                    max = stackk[i];
                }
            }

            printf("%d\n", max);
        }
    }

    return 0;
}