#include <bits/stdc++.h> 

// helper functions
bool compare(string &a, string &b) {
    int first = 0, second = 0;

    if(b.length() + 1 != a.length()) return false;

    while(first < a.length()) {
        if(a[first] == b[second]) {
            first++;
            second++;
        }
        else {
            first++;
        }
    }

    if(first == a.length() && second == b.length()) return true;
    return false;
}

bool comp(string &a, string &b) {
    return a.length() <= b.length();
}

int f(int i, int prev, vector<string> &arr, int n, vector<vector<int>>& dp) { //dp with memoization
    if(i == n) return 0;

    sort(arr.begin(), arr.end(), comp);

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = 0 + f(i+1, prev, arr, n, dp);
    int take = 0;
    if(prev == -1 || compare(arr[i], arr[prev])) {
        take = 1 + f(i+1, i, arr, n, dp);
    }

    return dp[i][prev+1] = max(take, notTake);
}

int longestStrChain(vector<string> &arr)
{ //not the most optimal but close to the most optimal solution
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;

    sort(arr.begin(), arr.end(), comp);

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            if(compare(arr[i], arr[j])){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}
