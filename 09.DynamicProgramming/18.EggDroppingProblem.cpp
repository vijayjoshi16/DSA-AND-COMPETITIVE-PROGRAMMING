#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int eggFloor[n+1][k+1];
        for(int i=1;i<=n;i++){
            eggFloor[i][1]=1;
            eggFloor[i][0]=0;
        }
        
        for(int i=1;i<=k;i++)
        eggFloor[1][i]=i;
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                eggFloor[i][j]=INT_MAX;
                for(int l=1;l<=j;l++){
                    eggFloor[i][j]=min(eggFloor[i][j],1+max(eggFloor[i-1][l-1],eggFloor[i][j-l]));
                }
            }
        }
        return eggFloor[n][k];
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Endss