
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int countSquares(int N) {
        // code here
        long long int ctr=0,lo=1,hi=N;
        while(lo<=hi){
            long long int mid=lo+(hi-lo)/2;
            long long int sq=mid*mid;
            if(sq==N)
            return mid-1;
            else if(sq>N)
            hi=mid-1;
            else{
                ctr=mid;
                lo=mid+1;
            }
        }
        return ctr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends