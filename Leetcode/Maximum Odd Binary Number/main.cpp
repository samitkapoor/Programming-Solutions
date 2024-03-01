class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(char ch: s) {
            if(ch == '1') ones++;
        }
        int zeros = s.length() - ones;

        if(ones == 0) return s;

        string res = "";
        while(ones != 1) {
            res += "1";
            ones--;
        }
        while(zeros--) res += "0";

        return res + "1";
    }
};
