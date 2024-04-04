class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int open = 0;

        for(char c : s) {
            if(c == '(') {
                open++;
                ans = max(ans, open);
            } else if(c == ')') {
                open--;
            }
        }

        return ans;
    }
};
