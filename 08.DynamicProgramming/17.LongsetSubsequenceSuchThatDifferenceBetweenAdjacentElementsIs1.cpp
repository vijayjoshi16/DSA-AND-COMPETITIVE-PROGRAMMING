// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        // code here
        int dp[N];
        for(int i=0;i<N;i++)
        dp[i]=1;
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(abs(A[i]-A[j])==1)
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int max=0;
        for(int i=0;i<N;i++){
            if(dp[i]>max)
            max=dp[i];
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
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends