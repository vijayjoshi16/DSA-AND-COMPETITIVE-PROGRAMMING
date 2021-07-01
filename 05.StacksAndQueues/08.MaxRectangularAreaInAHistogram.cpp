class Solution {
public:
    bool sortByFirst(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
                int l=intervals[i][0];
                int u=intervals[i][1];
                vector<int> cover;
                for(int j=i+1;j<n;j++){
                    if(intervals[j][0]<=u){
                        u=max(u,intervals[j][1]);
                        i++;
                    }
                }
                cover.push_back(l);
                cover.push_back(u);
                ans.push_back(cover);
        }
        return ans;
    }
};