#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &height)
{
    vector<int> minCost(n , 0);

    for(int i = 0 ; i<height.size() ; i++){
        if(i == 0) {
            continue;
        }
        else if(i == 1) {
            minCost[i] = abs(height[i] - height[i-1]);
        }
        else {
            minCost[i] = min(abs(height[i] - height[i-1]) + minCost[i-1], abs(height[i] - height[i-2]) + minCost[i-2]);
        }
    }

    return minCost[n-1];
}
