class Solution {
public:
    int minPartitions(string n) {
        
        sort(n.begin(), n.end());
        
        return n[n.length()-1] - '0';
        
    }
};
