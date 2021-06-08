class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        int maxi=1,st=0;
        
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                if(maxi==1){
                    maxi=2;
                    st=i;
                }
            }
        for(int i=1;i<n;i++){
            for(int j=0;j<n-i;j++){
                int k=j+i;
                //cout<<j<<" "<<k<<"\n";
                if(s[j]==s[k]&&dp[j+1][k-1]==1){
                    dp[j][k]=1;
                    if(k-j+1>maxi){
                        maxi=k-j+1;
                        st=j;
                    }
                }
            }
        }
        //cout<<maxi<<" "<<st<<" "<<e<<"\n";
        return s.substr(st,maxi);
    }
};