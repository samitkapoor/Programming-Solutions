class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        
        Arrays.sort(nums);
        
        for(int i=0 ; i<nums.length - 1 ; i++){
            int l = i+1;
            int r = nums.length-1;
            
            while(l<r){
                int t = nums[i] + nums[l] + nums[r];
                if(t > target){
                    r--;
                }else{
                    l++;
                }
                
                if(Math.abs(target-t) < Math.abs(target-result)){
                    result = t;
                }
            }
        }
        
        return result;
    }
}
