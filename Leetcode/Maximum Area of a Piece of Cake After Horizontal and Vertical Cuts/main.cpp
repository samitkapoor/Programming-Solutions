class Solution {
public:
    long long int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int h_cuts = horizontalCuts.size();
        int v_cuts = verticalCuts.size();
        
        long long int max_width = max(h - horizontalCuts[h_cuts-1], horizontalCuts[0]);
        long long int max_height = max(w - verticalCuts[v_cuts-1], verticalCuts[0]);
        
        for(int i=1 ; i<h_cuts ; i++){
            if(max_width < horizontalCuts[i]-horizontalCuts[i-1]){
                max_width = horizontalCuts[i]-horizontalCuts[i-1];   
            }
        }
        for(int i=1 ; i<v_cuts ; i++){
            if(max_height < verticalCuts[i]-verticalCuts[i-1]){
                max_height = verticalCuts[i]-verticalCuts[i-1];   
            }
        }
        
        return (max_height * max_width) % 1000000007;
    }
};
