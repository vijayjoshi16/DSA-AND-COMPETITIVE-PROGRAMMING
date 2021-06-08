// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2==1)
        return 0;
        int dp[sum/2+1];
        dp[0]=1;
        for(int i=1;i<=sum/2;i++)
        dp[i]=0;
        for(int i=0;i<N;i++){
            for(int j=sum/2;j>=arr[i];j--){
                if(dp[j-arr[i]]==1)
                dp[j]=1;
            }
        }
        return dp[sum/2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends