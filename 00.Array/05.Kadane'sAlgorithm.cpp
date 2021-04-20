#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int a[], int n){
    
    // Your code here
    int maxSoFar = INT_MIN,maxEndingHere = 0;
    for(int i=0;i<n;i++){
        maxEndingHere+=a[i];
        maxSoFar = max(maxSoFar,maxEndingHere);
        if(maxEndingHere < 0)
        maxEndingHere =0;
    }
    return maxSoFar;
    
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends