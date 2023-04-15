#include<bits/stdc++.h>

int binarySearch(vector<int> temp, int target) {
  int l = 0;
  int r = temp.size();

  while(l <= r) {
    int m = l + (r-l)/2;

    if(temp[m] >= target && (m == 0 || temp[m-1] < target)) return m;
    else if(temp[m] > target) r = m-1;
    else l = m + 1;
  }

  return -1;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1 ; i < n ; i++){
      if(arr[i] > temp.back()) {
        temp.push_back(arr[i]);
      } else {
        int ind = binarySearch(temp, arr[i]);
        temp[ind] = arr[i];
      }
    }

    return (int)temp.size();
}
