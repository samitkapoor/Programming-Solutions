class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> ms;
        unordered_map<char, char> mt;
        
        for(int i = 0 ; i < s.length() ; i++) {
            if(ms.find(s[i]) == ms.end() && mt.find(t[i]) == mt.end()){ 
                ms[s[i]] = t[i];
                mt[t[i]] = s[i];
            } else if(ms[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
