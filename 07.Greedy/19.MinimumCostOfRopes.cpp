#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq(arr,arr+n);
        long long res=0;
        while(pq.size()>=2){
            long long f=pq.top();
            pq.pop();
            long long s=pq.top();
            pq.pop();
            res+=f+s;
            pq.push(f+s);
        }
        return res;
    }
};


// { Driver Code Starts.
long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends