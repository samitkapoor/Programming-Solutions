#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin>>v[i];
        }
        
        for(int i =0 ; i < n ;i++){
            if(v[i] == 1) cout<<0<<" ";
            else cout<<1<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}
