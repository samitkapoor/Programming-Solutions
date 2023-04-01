class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<double> prev(m+1, 0);

        prev[0] = 1;

        for(int i = 1 ; i <= n ; i++){
            vector<double> curr(m+1, 0);
            curr[0] = 1;
            for(int j = 1 ; j <= m ; j++){
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
