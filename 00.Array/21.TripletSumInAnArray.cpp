#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends




class Solution{
    public:
    // function to find the triplet which sum to x
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for 
    
    bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
        int m[*max_element(a,a+n)]={};
        int maxi = *max_element(a,a+n);
        int tmp;
        for(int i=0;i<n;i++){
            m[a[i]-1]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n&&j!=i;j++){
                tmp=X-a[i]-a[j];
                if(tmp>0&&tmp<=maxi){
                    if(a[i]==tmp&&a[j]==tmp&&m[tmp-1]>=3){
                        return true;
                    }else if(a[i]==tmp&&a[j]!=tmp&&m[tmp-1]>=2){
                        return true;
                    }else if(a[j]==tmp&&a[i]!=tmp&&m[tmp-1]>=2){
                        return true;
                    }else if(a[i]!=tmp&&a[j]!=tmp&&m[tmp-1]>=1){
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends