#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int msis[n];
	    for(int i=0;i<n;i++)
	    msis[i]=arr[i];
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]&&(msis[j]+arr[i])>msis[i])
	            msis[i]=msis[j]+arr[i];
	        }
	    }
	    
	    int max=0;
	    for(int i=0;i<n;i++){
	        if(msis[i]>max)
	        max=msis[i];
	    }
	    return max;
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