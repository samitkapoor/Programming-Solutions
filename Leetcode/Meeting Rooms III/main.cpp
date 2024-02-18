class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0); 
        vector<long long int> ongoingmeetings(n, 0);

        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        for(int i = 0 ; i < meetings.size() ; i++){
            int minmeetingroom = 0;
            bool flag = true;
            for(int j = 0 ; j < n ; j++){
                if(ongoingmeetings[j] <= meetings[i][0]) {
                    ongoingmeetings[j] = meetings[i][1];
                    rooms[j]++;
                    flag = false;
                    break;
                }
                if(ongoingmeetings[minmeetingroom] > ongoingmeetings[j]) {
                    minmeetingroom = j;
                }
            }

            if(flag) {
                ongoingmeetings[minmeetingroom] += (meetings[i][1] - meetings[i][0]);
                rooms[minmeetingroom]++;
            }
        }

        int maxmeetingroom = 0;
        for(int i = 0 ; i < rooms.size() ; i++){
            if(rooms[i] > rooms[maxmeetingroom]) {
                maxmeetingroom = i;
            }
        }

        return maxmeetingroom;
    }
};
