#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.length(),m=B.length();
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        if(m+n!=C.length())
        return false;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if (i == 0 && j == 0)
                dp[i][j] = true;
                else if (i == 0) {
                    if (B[j - 1] == C[j - 1])
                        dp[i][j] = dp[i][j - 1];
                }else if (j == 0) {
                    if (A[i - 1] == C[i - 1])
                        dp[i][j] = dp[i - 1][j];
                }else if(A[i - 1] == C[i + j - 1]&& B[j - 1] != C[i + j - 1])
                    dp[i][j] = dp[i - 1][j];
                else if (A[i - 1] != C[i + j - 1]&& B[j - 1] == C[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                else if (A[i - 1] == C[i + j - 1]&& B[j - 1] == C[i + j - 1])
                    dp[i][j]= (dp[i - 1][j]|| dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends