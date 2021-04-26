#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends


class Solution{
    public:
    // Function to return maximum of sum without adjacent elements
    ll FindMaxSum(ll a[], ll n)
    {
        // Your code here
        ll loot[n][2];
        loot[0][0]=0;
        loot[0][1]=a[0];
        
        if(n>1){
            loot[1][0]=a[0];
            loot[1][1]=a[1];
        }
        for(ll i=2;i<n;i++){
            loot[i][0]=max(loot[i-1][0],loot[i-1][1]);
            loot[i][1]=a[i]+loot[i-1][0];
        }
        return max(loot[n-1][0],loot[n-1][1]);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends