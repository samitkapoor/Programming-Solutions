class Solution {
public:
    void formCombs(int ind, vector<string>&hash, vector<string>&result, string curr, string digits) {
        if(curr.size() == digits.size()) {
            result.push_back(curr);
            return;
        }

        for(int i = 0 ; i < hash[digits[ind]-'2'].size() ; i++){
            formCombs(ind + 1, hash, result, curr + hash[digits[ind]-'2'][i], digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        
        vector<string> result;

        vector<string> hash{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        formCombs(0, hash, result, "", digits);

        return result;
    }
};
