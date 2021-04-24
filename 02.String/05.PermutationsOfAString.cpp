#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> ans;
	    
	    void permute(string curr,int done[],int n,string s){
	        if(curr.length()==n){
	            ans.push_back(curr);
	        }else{
	            for(int i=0;i<n;i++){
	                if(done[i]==0){
	                    done[i]=1;
	                    permute(curr+s[i],done,n,s);
	                    done[i]=0;
	                }
	            }
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    int n = S.length();
		    int done[n]={};
		    sort(S.begin(),S.end());
		    permute("",done,n,S);
		    return ans;
		}
};


// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends