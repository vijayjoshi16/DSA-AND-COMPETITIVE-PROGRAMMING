//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        //code here
        if(n<=1)
	    return n;
	    else{
	        cpp_int catalan[n+1];
	        catalan[0]=catalan[1]=1;
	        for(int i=1;i<=n;i++){
	            catalan[i]=0;
	            for(int j=0;j<i;j++){
	                catalan[i]+=catalan[j]*catalan[i-j-1];
	            }
	        }
	        return catalan[n];
	    }
    }
};

// { Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}  // } Driver Code Ends