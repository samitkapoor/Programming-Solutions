class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxFreq = 0;
        for(int i: nums) {
            m[i]++;
            maxFreq = max(maxFreq, m[i]);
        }

        int answer = 0;
        for(pair<int, int> p: m) {
            if(p.second == maxFreq) answer += p.second;
        }

        return answer;
    }
};
