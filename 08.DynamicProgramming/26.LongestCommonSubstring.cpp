
 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        dp[i][m]=0;
        for(int i=0;i<=m;i++)
        dp[n][i]=0;
        int max=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(S1[i]==S2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    if(dp[i][j]>max)
                    max=dp[i][j];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends