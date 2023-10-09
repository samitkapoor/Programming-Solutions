class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string st = "";
        int countOpen = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') {
                countOpen++;
            }
            else if(s[i] == ')') {
                countOpen--;
            }
            
            if(countOpen < 0) {
                countOpen++;
                continue;
            }
            st += s[i];
        }
        
        if(countOpen == 0) {
            return st;
        }
        
        int k = st.length()-1;
        string ans = "";
        while(countOpen >= 0 && k >= 0) {
            if(st[k] == '(' && countOpen > 0) {
                k--;
                countOpen--;
            } else {
                ans += st[k];
                k--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
