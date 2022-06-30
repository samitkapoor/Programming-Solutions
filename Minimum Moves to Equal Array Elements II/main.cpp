class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        
        int m = n/2;
        
        int moves = 0;
        for(int i=0 ; i<n ; i++){
            moves += abs(nums[i] - nums[m]);
        }
        
        return moves;
    }
};
