class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
           return true;
        }

        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.length();
        int ans = 0;
        int temp = 0;

        for(int i = 0 ; i < n ; i++){
            if(i < k) {
                if(isVowel(s[i])) {
                    temp++;
                }
                ans = temp;
                continue;
            }
            if(isVowel(s[i-k])) {
                temp--;
            }
            if(isVowel(s[i])) {
                temp++;
            }

            ans = max(temp, ans);
        }

        return ans;
    }
};
