class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();

        if(n == k) return "0";

        string res = "";
        stack<char> st;

        int i = 0;
        while(i < n) {
            while(k > 0 && !st.empty() && st.top() > num[i]) st.pop(), k--;

            st.push(num[i]);
            i++;
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        while(res.size() > 1 && res[0] == '0') {
            res = res.substr(1);
        }

        return res;
    }
};
