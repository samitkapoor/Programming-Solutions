// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        // code here.
        vector<int> result;
        // we create a hashMap to keep track of all the visited elements
        unordered_map<int, int> hashMap;

        for (int i = 0; i < n1; i++)
        {
            // if A[i] is not found in the hashMap then kindly insert it and give it a value 1
            if (hashMap.find(A[i]) == hashMap.end())
            {
                hashMap.insert(make_pair(A[i], 1));
            }
        }

        for (int i = 0; i < n2; i++)
        {
            // if B[i] is found in hashMap that means B[i] is in A and B both so update the value to 2
            if (hashMap.find(B[i]) != hashMap.end())
            {
                hashMap[B[i]] = 2;
            }
        }

        for (int i = 0; i < n3; i++)
        {
            // if C[i] is found in the hashMap and its value is 2 then kindly insert the value to result
            // also update the value of hashMap to zero in order to restrict duplicates in the result
            if (hashMap.find(C[i]) != hashMap.end() && hashMap[C[i]] == 2)
            {
                hashMap[C[i]] = 0;
                result.push_back(C[i]);
            }
        }

        // return the result
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends