class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;

        sort(happiness.begin(), happiness.end());

        int counter = 0;
        for(int j = happiness.size() - 1; j >= 0; j--) {
            ans += happiness[j];
            counter++;
            if(j != 0)
                happiness[j-1] = max(0, happiness[j-1] - counter);
            if(counter == k) break;
        }

        return ans;
    }
};
