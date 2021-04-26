#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> c(32);
        for(int i=0;i<n;i++){
            int tmp=0,x=arr[i];
            while(x!=0){
                if(x%2)tmp++;
                x/=2;
            }
            c[tmp].push_back(arr[i]);
        }
        int ind=0;
        for(int i=31;i>=0;i--){
            for(int j=0;j<c[i].size();j++){
                arr[ind]=c[i][j];
                ind++;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends