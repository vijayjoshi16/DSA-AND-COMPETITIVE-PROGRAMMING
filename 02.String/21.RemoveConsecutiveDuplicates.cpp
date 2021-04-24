#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string s="";
        s+=S[0];
        for(int i=1;i<S.length();i++){
            if(s[s.length()-1]!=S[i]){
                s+=S[i];
            }
        }
        return s;
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
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends