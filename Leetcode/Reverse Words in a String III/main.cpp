class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string word = " ";
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ' ') {
                reverse(word.begin(), word.end());
                ans += word;
                word = "";
            }
            word += s[i];
        }

        reverse(word.begin(), word.end());
        ans += word.substr(0, word.length()-1);
        word = "";

        return ans;
    }
};
