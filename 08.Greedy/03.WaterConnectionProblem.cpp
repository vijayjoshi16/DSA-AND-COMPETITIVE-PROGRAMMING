#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int ans;
    
    int dfs(int w,int cd[],int wt[]){
        if(cd[w]==0)
        return w;
        if(wt[w]<ans)
        ans=wt[w];
        return dfs(cd[w],cd,wt);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int cd[1100]={0};
        int rd[1100]={0};
        int wt[1100]={0};
        vector<vector<int>> res;
        
        for(int i=0;i<p;i++){
            cd[a[i]]=b[i];
            wt[a[i]]=d[i];
            rd[b[i]]=a[i];
        }
        
        for(int j=1;j<=n;j++){
            if(rd[j]==0&&cd[j]){
                ans=INT_MAX;
                int w=dfs(j,cd,wt);
                vector<int> tmp;
                tmp.push_back(j);
                tmp.push_back(w);
                tmp.push_back(ans);
                res.push_back(tmp);
            }
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends