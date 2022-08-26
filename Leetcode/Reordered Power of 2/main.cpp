class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> digitsInN = digitsCounter(n);
        
        int x = 1;
        
        for(int i=0 ; i<31 ; i++){
            if(digitsInN == digitsCounter(x)){
                return true;
            }
            
            x = x<<1;
        }
        
        return false;
    }
    
    vector<int> digitsCounter(int n){
        vector<int> v(10, 0);
        
        while(n != 0){
            v[n%10]++;
            n/=10;
        }
        
        return v;
    }
};
