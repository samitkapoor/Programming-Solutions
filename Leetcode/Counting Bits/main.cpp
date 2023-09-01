class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;

        for(int i = 0 ; i <= n ; i++){
            int bits = 0;
            int temp = i;
            while(temp) {
                bits += temp & 1;
                temp >>= 1;
            }

            result.push_back(bits);
        }

        return result;
    }
};
