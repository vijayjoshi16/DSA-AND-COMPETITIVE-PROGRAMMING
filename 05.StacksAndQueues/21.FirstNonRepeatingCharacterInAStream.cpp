#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    int ctr[26]={0};
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        q.push(A[i]);
		        ctr[A[i]-'a']++;
		        while(!q.empty()){
		            if(ctr[q.front()-'a']>1)
		            q.pop();
		            else{
		                ans+=q.front();
		                break;
		            }
		        }
		        if(q.empty())
		        ans+="#";
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends