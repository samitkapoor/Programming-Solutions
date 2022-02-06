// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        string y = "";
        int s = -1;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '(' || x[i] == '{' || x[i] == '[')
            {
                y += x[i];
                s++;
            }
            else if (x[i] == ')' && s >= 0 && y[s] == '(')
            {
                y = y.substr(0, y.length() - 1);
                s--;
            }
            else if (x[i] == ']' && s >= 0 && y[s] == '[')
            {
                y = y.substr(0, y.length() - 1);
                s--;
            }
            else if (x[i] == '}' && s >= 0 && y[s] == '{')
            {
                y = y.substr(0, y.length() - 1);
                s--;
            }
            else
            {
                return false;
            }
        }

        if (y.length() != 0)
            return false;

        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends