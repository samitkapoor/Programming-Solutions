class Solution {
public:
    string makeGood(string s) {
        int i = 1;
        while(i < s.length()) {
            int n = s.length();
            if(i == 0) {
                i++;
                continue;
            }

            int a = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 'a' : s[i] - 'A';
            int b = s[i-1] >= 'a' && s[i-1] <= 'z' ? s[i-1] - 'a' : s[i-1] - 'A';  

            if(a == b && (((s[i-1] >= 'a' && s[i-1] <= 'z') && (s[i] >= 'A' && s[i] <= 'Z')) || ((s[i-1] >= 'A' && s[i-1] <= 'Z') && (s[i] >= 'a' && s[i] <= 'z')))) {
                s = s.substr(0, i-1) + s.substr(i+1);
                i--;
            } else i++;
        }

        return s;
    }
};
