// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution {
  public:
    bool valid(int a[],int n,int m,int mid){
        int st=1;
        int curr=0;
        for(int i=0;i<n;i++){
            if(a[i]>mid)
            return false;
            if(curr+a[i]>mid){
                curr=a[i];
                st++;
                if(st>m)
                return false;
            }else
            curr+=a[i];
        }
        return true;
    }
  
    int findPages(int a[], int n, int m) {
        //code here
        long long sum = accumulate(a,a+n,0);
        int lo=0,hi=sum,res=INT_MAX;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(valid(a,n,m,mid)){
                res=min(res,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends