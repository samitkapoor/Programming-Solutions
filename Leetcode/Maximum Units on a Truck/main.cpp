class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1];
        });
        
              
        int result = 0;
        
        for(vector<int> a : boxTypes){
            if(a[0] <= truckSize){
                result += (a[0]*a[1]);
                truckSize -= a[0];
            }
            else{
                result += (a[1] * truckSize);
                break;
            }
        }
        
        return result;
    }
};
