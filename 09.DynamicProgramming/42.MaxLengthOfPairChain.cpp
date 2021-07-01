class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }
        int max=dp[0];
        for(int i=1;i<n;i++)
            if(dp[i]>max)
                max=dp[i];
        return max;
    }
};