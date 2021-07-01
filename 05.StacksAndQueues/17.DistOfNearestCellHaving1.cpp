#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<vector<int>> ans;
	     vector<vector<bool>> vis;
	    int n=grid.size(),m=grid[0].size();
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        vector<int> anstmp;
	        vector<bool> vistmp;
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                anstmp.push_back(0);
	                vistmp.push_back(true);
	                q.push({i,j});
	            }else{
	                anstmp.push_back(INT_MAX);
	                vistmp.push_back(false);
	            }
	        }
	        ans.push_back(anstmp);
	        vis.push_back(vistmp);
	    }
	    int dx[]={0,1,0,-1};
	    int dy[]={1,0,-1,0};
	    int dist=0;
	    while(!q.empty()){
	        int lim=q.size();
	        dist++;
	        while(lim--){
	            int x=q.front().first,y=q.front().second;
	            q.pop();
	            for(int i=0;i<4;i++){
	                int nx=x+dx[i];
	                int ny=y+dy[i];
	                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==0){
	                    grid[nx][ny]=1;
	                    ans[nx][ny]=dist;
	                    q.push({nx,ny});
	                }
	            }
	        }
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends