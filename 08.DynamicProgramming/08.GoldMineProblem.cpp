// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int dp[n][m];
        for(int i=0;i<n;i++)
        dp[i][0]=M[i][0];
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                dp[j][i]=M[j][i];
                if(n==1){
                    dp[j][i]+=dp[j][i-1];
                }else if(j==0){
                    dp[j][i]+=max(dp[j][i-1],dp[j+1][i-1]);
                }else if(j==n-1){
                    dp[j][i]+=max(dp[j][i-1],dp[j-1][i-1]);
                }else{
                    dp[j][i]+=max(dp[j+1][i-1],max(dp[j][i-1],dp[j-1][i-1]));
                }
            }
        }
        
        int maxi=dp[0][m-1];
        for(int i=1;i<n;i++){
            if(dp[i][m-1]>maxi)
            maxi=dp[i][m-1];
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends