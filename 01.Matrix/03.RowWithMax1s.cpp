#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=-1,ind=m-1;
	    for(int i=0;i<n;i++){
	        if(arr[i][ind]==1){
	            ans=i;
	            int j;
	            for(j=ind-1;j>=0;j--){
	                if(arr[i][j]==0)
	                break;
	            }
	            ind=j+1;
	            if(ind==0)
	            break;
	            ind--;
	        }
	    }
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends