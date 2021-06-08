class Solution {
public:
    int longestPalindromeSubseq(string str) {
        int n=str.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        int i,j,k;
        for (i=2; i<=n; i++)
        {
            for (j=0; j<n-i+1; j++)
            {
                k = j+i-1;
                if (str[j] == str[k] && i == 2)
                   dp[j][k] = 2;
                else if (str[j] == str[k])
                   dp[j][k] = dp[j+1][k-1] + 2;
                else
                   dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
            }
        }

        return dp[0][n-1];
    }
};