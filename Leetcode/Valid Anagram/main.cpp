class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m;
        
        for(char c: s){
            m[c]++;
        }
        
        for(char c: t){
            if(m.find(c) == m.end() || m[c] == 0){
                return false;
            }
            
            m[c]--;
        }
        
        for(auto p : m){
            if(p.second != 0){
                return false;
            }
        }
        
        return true;
    }
};
