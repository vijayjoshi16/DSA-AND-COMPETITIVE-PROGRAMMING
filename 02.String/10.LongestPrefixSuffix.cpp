 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    // Your code goes here
	    int l=0,n=s.length();
	    if(n<2)
	    return 0;
	    int  len=0,i=1;
	    while(i<n){
	        if(s[i]==s[len]){
	            len++;
	            i++;
	        }else{
	            i=i-len+1;
	            len=0;
	        }
	    }
	    return len;
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends