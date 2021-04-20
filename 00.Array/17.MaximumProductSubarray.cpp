#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	
	long long int maxi(long long int a,long long int b){
	    if(a>b)
	    return a;
	    return b;
	}
	
	long long int mini(long long int a,long long int b){
	    if(a>b)
	    return b;
	    return a;
	}
	
	long long int maxProduct(int *arr, int n) {
	    // code here
	    long long int minVal = arr[0]; 
        long long int maxVal = arr[0]; 
      
        long long int maxProduct = arr[0]; 
      
        for (long long int i = 1; i < n; i++) { 
            if (arr[i] < 0) 
                swap(maxVal, minVal);  
            maxVal = maxi(arr[i], maxVal * arr[i]); 
            minVal = mini(arr[i], minVal * arr[i]); 
            maxProduct = maxi(maxProduct, maxVal); 
        } 
        return maxProduct; 
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends