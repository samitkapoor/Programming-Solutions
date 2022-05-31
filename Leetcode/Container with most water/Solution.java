class Solution {
    public int maxArea(int[] height) {
        int l = 0;
        int r = height.length-1;
        int max_area = 0;
        
        while(l<r){
            if(height[l] < height[r]){
                max_area = Math.max(max_area, height[l] * (r-l));
                l++;
            }
            else{
                max_area = Math.max(max_area, height[r] * (r-l));
                r--;
            }
        }
        
        
        return max_area;
    }
}
