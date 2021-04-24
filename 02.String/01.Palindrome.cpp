 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    for(int i=0;i<n/2;i++)
	    if(s[i]!=s[n-1-i])
	    return 0;
	    return 1;
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends