// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int m[N][N]={0};
        int tmp;
        for(int l=2;l<N;l++){
            for(int i=1;i<N-l+1;i++){
                int j=i+l-1;
                m[i][j]=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    tmp=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    if(tmp<m[i][j])
                    m[i][j]=tmp;
                }
            }    
        }
        return m[1][N-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends