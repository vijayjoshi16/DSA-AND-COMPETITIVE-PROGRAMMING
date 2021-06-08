#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{
		// Your code goes here
		if(N==0)
		return 0;
		
		if(N==1)
		return 10;
		
		long long even[10],odd[10];
		for(long long i=0;i<10;i++)
		odd[i]=1;
		long long isOdd=1;
		for(long long i=2;i<=N;i++){
		    isOdd=1-isOdd;
		    if(isOdd==0){
		        even[0] = odd[0] + odd[8];
		        even[1] = odd[1] + odd[2] + odd[4];
                even[2] = odd[2] + odd[1] + odd[3] + odd[5];
                even[3] = odd[3] + odd[2] + odd[6];
                even[4] = odd[4] + odd[1] + odd[5] + odd[7];
                even[5] = odd[5] + odd[2] + odd[4] + odd[8] + odd[6];
                even[6] = odd[6] + odd[3] + odd[5] + odd[9];
                even[7] = odd[7] + odd[4] + odd[8];
                even[8] = odd[8] + odd[0] + odd[5] + odd[7] + odd[9];
                even[9] = odd[9] + odd[6] + odd[8];
            }
            else
            {
                odd[0] = even[0] + even[8];
                odd[1] = even[1] + even[2] + even[4];
                odd[2] = even[2] + even[1] + even[3] + even[5];
                odd[3] = even[3] + even[2] + even[6];
                odd[4] = even[4] + even[1] + even[5] + even[7];
                odd[5] = even[5] + even[2] + even[4] + even[8] + even[6];
                odd[6] = even[6] + even[3] + even[5] + even[9];
                odd[7] = even[7] + even[4] + even[8];
                odd[8] = even[8] + even[0] + even[5] + even[7] + even[9];
                odd[9] = even[9] + even[6] + even[8];
            }
		}
		long long totalCount=0;
		if(isOdd==1){
		    for(long long i=0;i<10;i++)totalCount+=odd[i];
		}else{
		    for(long long i=0;i<10;i++)totalCount+=even[i];
		}
		return totalCount;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends