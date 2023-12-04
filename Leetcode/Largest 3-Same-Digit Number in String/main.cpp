class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        for(int i = 1 ; i < num.length()-1 ; i++){
            if(num[i-1] == num[i] && num[i] == num[i+1]){
                string temp = num.substr(i-1,3);
                if(result == "" || result[0] < temp[0]) {
                    result = temp;
                }
            }
        }
        
        return result;
    }
};
