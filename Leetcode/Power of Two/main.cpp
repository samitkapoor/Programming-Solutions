class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        
        unsigned long long int x = 1;
        while(x <= n){
            if(x == n) return true;
            x = x * 2;
        }

        return false;
    }
};
