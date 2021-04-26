//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

// your code will be pasted here

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}// } Driver Code Ends


//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
   
    //code here 
    long long int left[n],right[n];
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    left[i]=left[i-1]*a[i-1];
    for(int i=n-2;i>=0;i--)
    right[i]=right[i+1]*a[i+1];
    vector<long long int> ans(n);
    for(int i=0;i<n;i++)
    ans[i]=left[i]*right[i];
    return ans;
}
