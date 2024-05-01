class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0, n = word.length();
        while(index < n && word[index] != ch) index++;
        if(index == n) return word;

        string prefix = word.substr(0, index+1);
        string suffix = word.substr(index+1);

        reverse(prefix.begin(), prefix.end());

        return prefix + suffix;
    }
};
