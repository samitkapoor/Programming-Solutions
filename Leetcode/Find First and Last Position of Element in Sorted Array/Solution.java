class Solution {
    public int[] searchRange(int[] nums, int target) {
        int result[] = new int[2];
        result[0] = result[1] = -1;
        
        int l = 0;
        int r = nums.length - 1;
        
        while(l <= r){
            int m = l + (r-l)/2;
            
            if(nums[m] == target && (m==0 || nums[m-1] != target)){
                result[0] = m;
                break;
            }
            else if(nums[m] < target){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        
        if(result[0] != -1){
            for(int i = result[0] ; i<nums.length && nums[i] == target ; i++){
                result[1] = i;
            }
        }
        return result;
    }
}
