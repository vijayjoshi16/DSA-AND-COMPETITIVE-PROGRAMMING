// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int sum[R][C+1];
        for(int i=0;i<R;i++){
            sum[i][0]=0;
            for(int j=1;j<=C;j++){
                sum[i][j]=sum[i][j-1]+M[i][j-1];
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<C;i++){
            for(int j=i;j<C;j++){
                int maxsofar=INT_MIN,maxendinghere=0;
                for(int k=0;k<R;k++){
                    maxendinghere+=sum[k][j+1]-sum[k][i];
                    if(maxendinghere>maxsofar)
                    maxsofar=maxendinghere;
                    if(maxendinghere<0)
                    maxendinghere=0;
                }
                //cout<<i<<" "<<j<<" "<<maxsofar<<"\n";
                if(maxsofar>maxi)
                maxi=maxsofar;
            }
        }
        return maxi;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends