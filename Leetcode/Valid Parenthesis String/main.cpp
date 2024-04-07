class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                leftMin++, leftMax++;
            } else if(s[i] == ')') {
                leftMin--;
                leftMax--;
                
                if(leftMin < 0) leftMin = 0;
                if(leftMax < 0) return false;
            } else if(s[i] == '*') {
                leftMin--;
                leftMax++;
                if(leftMin < 0) leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};
