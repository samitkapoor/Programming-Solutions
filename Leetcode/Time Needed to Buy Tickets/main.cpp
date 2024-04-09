class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        int limit = tickets[k];

        for(int i = 0 ; i < tickets.size() ; i++){ 
            if(i <= k) {
                sum += min(limit, tickets[i]);
            } else {
                sum += min(limit-1, tickets[i]);
            }
        }

        return sum;
    }
};
