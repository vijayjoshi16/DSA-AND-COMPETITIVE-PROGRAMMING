// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int k=K,n=N;
        int dp[k+1][n+1];
        for(int i=0;i<=k;i++)
        dp[i][0]=0;
        for(int i=0;i<=n;i++)
        dp[0][i]=0;
        for(int i=1;i<=k;i++){
            int pre=INT_MIN;
            for(int j=1;j<n;j++){
                pre=max(pre,dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1],A[j]+pre);
            }
        }
        return dp[k][n-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends