#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        
        // your code here
        int maji=0,ctr=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[maji])
            ctr++;
            else
            ctr--;
            if(ctr<0){
            maji=i;ctr=1;}
        }
        ctr=0;
        for(int i=0;i<n;i++)
        if(a[i]==a[maji])
        ctr++;
        if(ctr>n/2)
        return a[maji];
        else
         return -1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends