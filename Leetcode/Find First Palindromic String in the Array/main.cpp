class Solution {
public:
    bool isPalindrome(string& word) {
        int left = 0, right = word.length() - 1;

        while(left <= right) {
            if(word[left] != word[right]) return false;
            left++, right--;
        }

        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(string word: words) {
            if(isPalindrome(word)) return word;
        }

        return "";
    }
};
