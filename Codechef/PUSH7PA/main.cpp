#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int, int> m;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            m[x]++;
        }
        
        int result = 0;
        for(auto p : m){
            result = max(result, p.first + p.second - 1);
        }

        cout<<result<<endl;
    }

    return 0;
}