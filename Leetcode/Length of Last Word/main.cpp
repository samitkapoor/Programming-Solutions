class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = 0;
        int curr = 0;

        for(char ch : s) {
            if(ch == ' ' && curr != 0) last = curr, curr = 0;
            else if(ch != ' ') curr++;
        }
        if(curr != 0)
            last = curr;

        return last;
    }
};
