class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max = 1;

        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[max] < arr[i]) {
                max = i;
            }
        }

        return max;
    }
};
