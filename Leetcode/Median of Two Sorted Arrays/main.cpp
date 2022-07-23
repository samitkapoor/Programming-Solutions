class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> v(m+n);
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                v[k] = nums1[i];
                i++;
            }
            else{
                v[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while(i < m){
            v[k] = nums1[i];
            k++;
            i++;
        }
        
        while(j < n){
            v[k] = nums2[j];
            k++;
            j++;
        }
        
        int x = m + n;
        
        if(x % 2 == 0){
            i = x/2;
            j = x/2-1;
            
            return (double)(v[i]+v[j])/2;
        }
        
        return (double)v[x/2];
    }
};
