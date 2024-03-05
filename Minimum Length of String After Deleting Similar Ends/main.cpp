class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;

        char curr;

        while(left < right) {
            if(s[left] == s[right]) {
                curr = s[left];
                left++;
                right--;
            } else if(s[left] == curr) {
                left++;
            } else if(s[right] == curr) {
                right--;
            } else {
                break;
            }
        }

        if(left == right && s[left] == curr) return 0;

        return right - left + 1;
    }
};
