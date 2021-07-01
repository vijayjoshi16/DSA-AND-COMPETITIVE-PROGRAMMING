#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        int dp[N];
        dp[0]=0;
        for(int i=1;i<N;i++){
            dp[i]=dp[i-1];
            if(arr[i]-arr[i-1]<K){
                if(i>=2)
                dp[i]=max(dp[i],dp[i-2]+arr[i-1]+arr[i]);
                else
                dp[i]=max(dp[i],arr[i-1]+arr[i]);
            }
        }
        return dp[N-1];
        
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends