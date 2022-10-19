//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int a[], int b[], int m, int n)
    {
        int result = 0;
        
        int x = 0 , y = 0;
        
        int i = 0 , j = 0;
        
        while( i < m && j < n ){
            if( a[i] < b[j] ){
                x += a[i];
                i++;
            }
            else if( b[j] < a[i] ){
                y += b[j];
                j++;
            }
            else{
                result += max(x,y);
                
                x = 0;
                y = 0;
                
                result += a[i];
                i++;
                j++;
            }
        }
        
        while( i < m ){
            x += a[i];
            i++;
        }
        
        while( j < n ){
            y += b[j];
            j++;
        }
        
        result += max(x, y);
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends
