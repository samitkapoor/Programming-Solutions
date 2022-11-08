class Solution {
public:
    string makeGood(string s) {
        if(s.length() < 2){
            return s;
        }
        
        vector<char> stk;
        
        for(auto curr : s){
            if( stk.size() != 0 && abs(stk[stk.size()-1] - curr) == 32){
                stk.pop_back();
            }
            else{
                stk.push_back(curr);
            }
        }
        
        string res = "";
        for(char c : stk){
            res += c;
        }
        
        return res;
    }
};
