#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // code here 
        int n=s.length();
        int ctr=0,bal=0,p=0;
        vector<int> pos;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '[')
                pos.push_back(i);
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                bal++;
                p++;
            }
            else bal--;
            if(bal<0){
                ctr+=pos[p]-i;
                swap(s[i],s[pos[p]]);
                p++;
                bal=1;
            }
        }
        return ctr;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends