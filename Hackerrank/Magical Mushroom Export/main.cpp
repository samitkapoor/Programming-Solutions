#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    
    while(t--){ 
        int n, k;
        cin>>n>>k;
        
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }
        
        int temp = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if(i < k){
                temp += v[i];
                ans = temp;
            } else {
                temp -= v[i-k];
                temp += v[i];
                ans = max(ans, temp);
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
