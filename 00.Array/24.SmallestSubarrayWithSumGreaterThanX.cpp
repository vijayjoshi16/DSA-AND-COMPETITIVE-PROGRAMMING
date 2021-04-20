#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}// } Driver Code Ends




int sb(int a[], int n, int x)
{
    // Your code goes here   
    int start=0,end=0,sum=0,mini=INT_MAX;
    while(end<n){
        while(sum<=x&&end<n){
            sum+=a[end++];
        }
        while(sum>x&&start<n){
            if(end-start<mini)
            mini=end-start;
            sum-=a[start++];
        }
    }
    return mini;
}