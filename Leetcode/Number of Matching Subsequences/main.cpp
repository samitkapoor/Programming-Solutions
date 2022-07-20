class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> m;
        int counter = 0;
        
        for(int i=0 ; i<s.length() ; i++){
            m[s[i]].push_back(i);
        }
        
        for(int i=0 ; i<words.size() ; i++){
            string current = words[i];
            int last = -1;
            
            for(int j=0 ; j<current.length() ; j++){
                auto it = upper_bound(m[current[j]].begin(), m[current[j]].end(), last);
                
                if(it == m[current[j]].end()){
                    break;
                }
                
                last = *it;
                
                if(j == current.size()-1){
                    counter++;
                }
            }
        }
        
        return counter;        
    }
};
