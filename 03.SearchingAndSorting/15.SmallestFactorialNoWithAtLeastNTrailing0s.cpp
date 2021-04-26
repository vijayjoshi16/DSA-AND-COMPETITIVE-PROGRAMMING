
 // } Driver Code Ends


class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        long long lo=0,hi=5*n,tmp,ctr,ans;
        while(lo<=hi){
            long long mid = (hi+lo)/2;
            tmp=5;
            ctr=0;
            while(mid>=tmp){
                ctr+=mid/tmp;
                tmp*=5;
            }
            if(ctr>=n){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends