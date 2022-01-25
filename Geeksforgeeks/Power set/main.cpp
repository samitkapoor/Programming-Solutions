// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        // logic is to run the loop from 1 to (length of the string - 1) and selecting all those elements whose bits are set
        // total number of elements in the power set will be 2^(n-1)
        vector<string> result(pow(2, s.length()) - 1);
        for (int i = 1; i < pow(2, s.length()); i++)
        {
            string a = "";
            for (int j = 0; j < s.length(); j++)
            {
                // checking if jth bit is set in i
                if ((i & (1 << j)) != 0)
                {
                    a += s[j];
                }
            }
            // inserting the created subset
            result[i - 1] = a;
        }
        // sorting the vector before returning
        sort(result.begin(), result.end());

        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s);
        for (auto i : res)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends