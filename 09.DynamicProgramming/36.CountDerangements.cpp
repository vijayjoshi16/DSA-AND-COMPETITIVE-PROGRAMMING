// Initial function Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long int disarrange(int N){
        // code here
        if(N==1||N==2)
        return N-1;
        
        long int MOD=1000000007;
        long int a=0,b=1;
        for(long int i=3;i<=N;i++){
            long int tmp=((i-1)*((a+b)%MOD))%MOD;
            a=b;
            b=tmp;
        }
        return b;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.disarrange(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends