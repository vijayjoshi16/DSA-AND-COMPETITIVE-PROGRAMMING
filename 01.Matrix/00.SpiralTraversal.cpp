#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int u=0,d=r-1,l=0,rt=c-1,m=0,x=0,y=0;
        vector<int> ans;
        while(d>=u&&rt>=l){
            if(m==0){
                if(y<=rt){
                    ans.push_back(matrix[u][y]);
                    y++;
                }else{
                    u++;
                    x++;
                    y--;
                    m=1;
                }
            }else if(m==1){
                if(x<=d){
                    ans.push_back(matrix[x][rt]);
                    x++;
                }else{
                    y--;
                    x--;
                    rt--;
                    m=2;
                }
            }else if(m==2){
                if(y>=l){
                    ans.push_back(matrix[d][y]);
                    y--;
                }else{
                    d--;
                    y++;
                    x--;
                    m=3;
                }
            }else{
                if(x>=u){
                    ans.push_back(matrix[x][l]);
                    x--;
                }else{
                    x++;
                    l++;
                    y++;
                    m=0;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends