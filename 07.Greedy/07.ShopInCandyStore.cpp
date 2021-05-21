#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        sort(candies,candies+n);
        
        vector<int> ans(2);
        ans[0]=ans[1]=0;
        
        int i1=0,i2=n-1;
        while(i1<=i2){
            ans[0]+=candies[i1];
            i1++;
            i2-=k;
        }
        
        i1=0,i2=n-1;
        
        while(i1<=i2){
            ans[1]+=candies[i2];
            i2--;
            i1+=k;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends