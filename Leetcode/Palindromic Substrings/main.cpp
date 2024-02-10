class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> substrings(s.length(), vector<int>(s.length(), 0));

        int counter = 0;

        for(int gap = 0 ; gap < s.length() ; gap++){
            for(int i = 0, j = gap ; j < s.length() ; i++, j++){
                if(gap == 0) {
                    substrings[i][j] = 1;
                } else if(gap == 1) {
                    if(s[i] == s[j]) substrings[i][j] = 1;
                } else {
                    if(s[i] == s[j] && substrings[i+1][j-1] == 1) substrings[i][j] = 1;
                }

                if(substrings[i][j] == 1) counter++;
            }
        }

        return counter;
    }
};
