#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int x[]={1,0,-1,0};
        int y[]={0,1,0,-1};
        int n=grid.size(),m=grid[0].size();
        int oc=0,rc=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>=1)
                oc++;
                if(grid[i][j]==2){
                    rc++;
                    q.push({i,j});
                }
            }
        }
        int t=0;
        while(!q.empty()){
            if(rc==oc)
            return t;
            
            t++;
            int lim=q.size();
            while(lim--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newRow=row+x[i],newCol=col+y[i];
                    if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m&&grid[newRow][newCol]==1){
                        q.push({newRow,newCol});
                        grid[newRow][newCol]=2;
                        rc++;
                    }
                }
            }
        }
        if(rc==oc)
        return t;
        else
        return -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends