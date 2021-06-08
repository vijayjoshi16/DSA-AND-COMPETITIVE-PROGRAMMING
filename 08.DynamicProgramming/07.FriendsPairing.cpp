#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        if(n<=2)
        return n;
        long long a=1,b=2,c;
        for(int i=3;i<=n;i++){
            c=(b+((i-1)*a)%1000000007)%1000000007;
            a=b;
            b=c;
        }
        return (int)b;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends