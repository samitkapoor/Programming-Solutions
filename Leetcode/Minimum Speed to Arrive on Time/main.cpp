class Solution {
public:
    double calcTime(vector<int>& dist, int speed) {
        double time = 0.0;
        for(int i = 0 ; i < dist.size() ; i++) {
            double t = (double)dist[i]/(double)speed;

            time += ((i == dist.size() - 1) ? t : ceil(t)); 
        }

        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        int l = 1;
        int r = 1e7;

        int ans = -1;

        while(l <= r) {
            int m = l + (r - l) / 2;

            if(calcTime(dist, m) <= hour) {
                ans = m;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return ans;
    }
};

//s = d / t
