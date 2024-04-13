class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n, 0);
        vector<int> rightSmall(n, 0);

        stack<int> st;
        for(int i = 0 ; i < n ; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) leftSmall[i] = 0;
            else leftSmall[i] = st.top() + 1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1 ; i >= 0 ; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(st.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = st.top() - 1;

            st.push(i);
        }

        int maxA = 0;
        for(int i = 0 ; i < n ; i++) {
            maxA = max(maxA, (rightSmall[i] - leftSmall[i] + 1) * heights[i]);
        }

        return maxA;
    }
};
