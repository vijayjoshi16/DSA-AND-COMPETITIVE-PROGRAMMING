// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        int n=str.length();
        bool palindrome[n][n];
        for(int i=0;i<n;i++){
            palindrome[i][i]=true;
        }
        for(int i=0;i<n-1;i++){
            if(str[i]==str[i+1])
            palindrome[i][i+1]=true;
            else
            palindrome[i][i+1]=false;
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=l+i-1;
                if(str[i]==str[j]&&palindrome[i+1][j-1])
                palindrome[i][j]=true;
                else
                palindrome[i][j]=false;
            }
        }
        int cuts[n];
        for(int i=0;i<n;i++){
            if(palindrome[0][i])
            cuts[i]=0;
            else{
                cuts[i]=INT_MAX;
                for(int j=0;j<i;j++){
                    if(palindrome[j+1][i]&&(cuts[j]+1<cuts[i])){
                        cuts[i]=cuts[j]+1;
                    }
                }
            }
        }
        return cuts[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends