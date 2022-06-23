class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> jumps(n,0);
        
        for(int i = n-2 ; i>=0 ; i--){
            int j = i+1;
            int minimum = 10000;
            
            while(j < n && j <= (i+nums[i])){
                minimum = min(minimum, 1+jumps[j]);
                
                j++;
            }            
            
            jumps[i] = minimum;
        }
        
        return jumps[0];
    }
};
