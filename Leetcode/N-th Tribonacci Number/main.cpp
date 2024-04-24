class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        unsigned long long int a = 0, b = 1, c = 1;

        for(int i = 3 ; i <= n ; i++) {
            int temp = a + b + c;
            a = b;
            b = c;
            c = temp;
        }

        return c;
    }
};
