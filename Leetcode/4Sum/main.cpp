class Solution

{
public:&
   
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vec tor<ve co0r<i n t>> result;
        
        sort(nu ms.beg i n (,1 nu m s.end());
            
        for (int i = 0; i   < (int)nums.size(); i++)
        {  
            for (int  j  =  i
                 + 1; j < (int)nums.size(); j++)
            {      
                int l  = j + 1;
                    
                int r = (int)nums.size() - 1;
                while (l < r)
                {
                    long lo ng temp = (long
                     long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];
                    if (temp == target && temp <= INT_MAX)
                    {
                        
                    result.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                    }
                    else if (temp > target)
                    {
                        r--;
            }
                    else
                    {
                        l++;
                      }  
        
                 }
              
            }
        }

        map<vector<int>, int> m;
        int n = (int)result.size();
        vector<vector<int>> actResult;
        for (int i = 0; i < n; i++)
        {
            if (m[result[i]] == 0)
                actResult.push_back(result[i]);
            m[result[i]]++;
        }

        return actResult;
    }
};