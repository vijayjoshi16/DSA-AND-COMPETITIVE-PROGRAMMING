#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s1, string s2) {
        // Code here
        int p=s1.length(),q=s2.length();
        int ed[p+1][q+1];
	    for(int i=0;i<=p;i++){
	        for(int j=0;j<=q;j++){
	            if(!i)
	            ed[i][j]=j;
	            else if(!j)
	            ed[i][j]=i;
	            else if(s1.at(i-1)==s2.at(j-1))
	            ed[i][j]=ed[i-1][j-1];
	            else
	            ed[i][j]=min(ed[i][j-1],min(ed[i-1][j-1],ed[i-1][j]))+1;
	        }
	    }
	    return ed[p][q];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends