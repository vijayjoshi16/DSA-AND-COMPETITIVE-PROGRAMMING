#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 


class Solution{
    public:
    string smallestWindow (string s, string p){
        // Your code here
        int n=s.length(),m=p.length();
        if(n<m)
        return "-1";
        int h1[256]={};
        int h2[256]={};
        for(int i=0;i<m;i++)
        h1[p[i]]++;
        int start=0,si=-1,mini=INT_MAX,ctr=0;
        for(int i=0;i<n;i++){
            h2[s[i]]++;
            if(h2[s[i]]<=h1[s[i]])
            ctr++;
            if(ctr==m){
                while(h2[s[start]]>h1[s[start]]||h1[s[start]]==0){
                    if(h2[s[start]]>h1[s[start]]){
                        h2[s[start]]--;
                    }
                    start++;
                }
                int len = i-start+1;
                if(len<mini){
                    mini=len;
                    si=start;
                }
            }
        }
        if(si==-1)
        return "-1";
        return s.substr(si,mini);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends