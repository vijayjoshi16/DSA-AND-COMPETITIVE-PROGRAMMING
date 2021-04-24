// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i;
        int n=arr.size();
        for(i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                break;
            }   
        }
        if(i!=0){
            int tmp=arr[i-1],mini=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[mini]&&arr[j]>tmp)
                mini=j;
            }
            swap(arr[i-1],arr[mini]);
            sort(arr.begin()+i,arr.end());
        }else{
            sort(arr.begin(),arr.end());
        }
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends