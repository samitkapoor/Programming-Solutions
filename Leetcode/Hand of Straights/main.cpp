class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for(int x : hand) m[x]++;
        
        for(auto it : m){
            if(it.second>0){
                
                for(int i = 1 ; i < groupSize ; i++){
                    m[it.first + i] -= m[it.first];
                    if(m[it.first + i ] < 0) return false;
                }
                
            }
        }
        
        return true;
    }
};
