

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int maxsofar=-1,maxendinghere=0;
	    for(int i=0;i<S.length();i++){
	        int tmp=S[i]=='1'?-1:1;
	        maxendinghere+=tmp;
	        if(maxendinghere>maxsofar)
	        maxsofar=maxendinghere;
	        if(maxendinghere<0)
	        maxendinghere=0;
	    }
	    return maxsofar;
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

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends