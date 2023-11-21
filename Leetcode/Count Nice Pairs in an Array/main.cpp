class Solution {
public:
    int reverse(int n) {        
        int num = 0;
        while(n != 0) {
            num = num * 10 + n % 10;
            n/=10;
        }
        
        return num;
    }
    
    int countNicePairs(vector<int>& nums) {
        int counter = 0;
        unordered_map<int, int> m;
        const int MOD = 1e9+7;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int diff = nums[i] - reverse(nums[i]);
            if(m[diff] != 0) {
                counter = (counter + m[diff])%MOD;
            }
            m[diff]++;
        }
        
        return counter;
    }
};
