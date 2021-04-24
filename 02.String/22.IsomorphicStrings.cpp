// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends


class Solution{
  public:
    // This function returns true if str1 and str2 are ismorphic
    // else returns false
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        bool marked[256]={false};
        int m[256];
        memset(m,-1,sizeof(m));
        int n=str1.length(),m1=str2.length();
        int i1=0,i2=0;
        if(n!=m1)
        return false;
        for(int i=0;i<n;i++){
            if(m[str1[i]]==-1){
                if(marked[str2[i]])
                return false;
                marked[str2[i]]=true;
                m[str1[i]]=str2[i];
            }else{
                if(m[str1[i]]!=str2[i])
                return false;
            }
        }
        return true;
        
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends