#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends

int first(int a[],int n,int x,int lo,int hi){
   if(lo<=hi){
       int mid=(lo+hi)/2;
       if(a[mid]==x&&(mid==0||a[mid-1]<x))
       return mid;
       else if(x>a[mid])
       return first(a,n,x,mid+1,hi);
       else 
       return first(a,n,x,lo,mid-1); 
   }
   return -1;
}

int last(int a[],int n,int x,int lo,int hi){
   if(lo<=hi){
       int mid=(lo+hi)/2;
       if(a[mid]==x&&(mid==n-1||a[mid+1]>x))
       return mid;
       else if(x<a[mid])
       return last(a,n,x,lo,mid-1);
       else 
       return last(a,n,x,mid+1,hi); 
   }
   return -1;
}

vector<int> find(int a[], int n , int x )
{
    // code here
    vector<int> v;
    v.push_back(first(a,n,x,0,n-1));
    v.push_back(last(a,n,x,0,n-1));
    return v;
    
}