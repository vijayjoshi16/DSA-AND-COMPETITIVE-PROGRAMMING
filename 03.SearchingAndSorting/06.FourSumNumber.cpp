#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &a, int tgt) {
        // Your code goes here
        sort(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>> vec;
        set<vector<int>> s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1;
                while(l<r){
                    if(a[i]+a[j]+a[l]+a[r]==tgt){
                        vector<int> v;
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[l]);
                        v.push_back(a[r]);
                        if(s.find(v)==s.end())
                        vec.push_back(v);
                        s.insert(v);
                        l++;
                        r--;
                    }else if(a[i]+a[j]+a[l]+a[r]<tgt)
                    l++;
                    else
                    r--;
                }
            }
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends