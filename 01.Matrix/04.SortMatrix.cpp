// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> tmp;
        for(int i=0;i<Mat.size();i++){
            for(int j=0;j<Mat[0].size();j++){
                tmp.push_back(Mat[i][j]);
            }
        }
        sort(tmp.begin(),tmp.end());
        vector<vector<int>> ans;
        for(int i=0;i<Mat.size();i++){
            vector<int> v;
            for(int j=0;j<Mat[0].size();j++){
                v.push_back(tmp[Mat[0].size()*i+j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends