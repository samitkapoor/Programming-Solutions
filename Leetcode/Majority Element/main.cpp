class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force approach
        // int max_freq = 0;
        // int result = nums[0];
        // for(int number: nums) {
        //     int frequency = 0;
        //     for(int i: nums) {
        //         if(number == i) frequency++;
        //     }

        //     if(frequency > max_freq) {
        //         max_freq = frequency;
        //         result = number;
        //     }
        // }

        // return result;

        map<int, int> m;
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }

        int max_freq = 0;
        int result = nums[0];
        for(auto pair: m) {
            if(pair.second > max_freq) {
                result = pair.first;
                max_freq = pair.second;
            }
        }

        return result;
    }
};
