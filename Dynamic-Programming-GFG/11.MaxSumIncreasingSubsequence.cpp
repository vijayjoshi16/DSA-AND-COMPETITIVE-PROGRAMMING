#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    vector<int> mth(n);
	    for(int i=0;i<n;i++){
	        mth[i]=a[i];
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i]){
	                mth[i]=max(mth[i],a[i]+mth[j]);
	            }
	        }
	    }
	    return *max_element(mth.begin(),mth.end());
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends