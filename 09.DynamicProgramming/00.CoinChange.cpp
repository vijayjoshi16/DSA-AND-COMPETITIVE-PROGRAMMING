#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        //code here.
        long long int dp[n+1][m];
        memset(dp,0,sizeof dp);
        for (long long int i = 0; i < m; i++)
            dp[0][i] = 1;
        for(long long int i=1;i<=n;i++){
            for(long long int j=0;j<m;j++){
                if(S[j]<=i)
                dp[i][j]+=dp[i-S[j]][j];
                if(j>=1)
                dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[n][m-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends