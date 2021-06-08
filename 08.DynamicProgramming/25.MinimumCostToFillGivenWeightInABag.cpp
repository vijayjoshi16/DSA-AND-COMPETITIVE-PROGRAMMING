#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        int minCost[W+1];
        for(int i=0;i<=W;i++)minCost[i]=-1;
        minCost[0]=0;
        minCost[1]=cost[0];
        for(int i=2;i<=W;i++){
            for(int j=0;j<N;j++){
                if(cost[j]!=-1&&i>=j+1&&minCost[i-j-1]!=-1){
                    if(minCost[i]==-1)
                    minCost[i]=cost[j]+minCost[i-j-1];
                    else
                    minCost[i]=min(minCost[i],cost[j]+minCost[i-j-1]);
                }
            }
        }
        return minCost[W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends