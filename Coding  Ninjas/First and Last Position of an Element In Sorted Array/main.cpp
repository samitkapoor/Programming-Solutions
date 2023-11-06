int lower_bound(int x, vector<int>& arr) {
    int left = 0;
    int right = arr.size()-1;
    int ans = -1;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == x) {
            ans = mid;
            right = mid-1;
        } else if(arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int upper_bound(int x, vector<int> &arr) { //6 
    int left = 0;
    int right = arr.size()-1;
    int ans = -1;

    while(left <= right) {
        int mid = left + (right-left)/2;

        if(arr[mid] <= x) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    } 

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int x = lower_bound(k, arr);
    int y = upper_bound(k, arr);

    if(arr[x] != k) return {-1, -1};
    else if(y == -1) return {x, n-1};

    return {x, y-1};
}
