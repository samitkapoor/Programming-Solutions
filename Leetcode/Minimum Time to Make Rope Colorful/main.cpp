class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int currTime = 0, totalTime = 0;

        for(int i = 0 ; i < colors.size() ; i++) {
            if(i != 0 && colors[i] != colors[i-1]) {
                currTime = 0;
            }

            if(currTime > neededTime[i]) {
                totalTime += neededTime[i];
            } else {
                totalTime += currTime;
                currTime = neededTime[i];
            }
        }

        return totalTime;
    }
};
