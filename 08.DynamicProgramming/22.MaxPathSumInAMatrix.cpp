// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        for(int i=0;i<N;i++){
            dp[N-1][i]=Matrix[N-1][i];
        }
        
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<N;j++){
                int ld=0,rd=0,d=0;
                if(j>0)
                ld=dp[i+1][j-1];
                if(j<N-1)
                rd=dp[i+1][j+1];
                d=dp[i+1][j];
                dp[i][j]=Matrix[i][j]+max(d,max(rd,ld));
            }
        }
        int max=0;
        for(int i=0;i<N;i++){
            if(dp[0][i]>max)
            max=dp[0][i];
        }
        return max;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends