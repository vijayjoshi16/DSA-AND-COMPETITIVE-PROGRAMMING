class Solution {
public:
    int maxProfit(vector<int>& a) {
        int maxPro=0;
        int buy=-1,sell=-1,min=-1;
        int n=a.size();
        for(int i=0;i<n-1;i++){
            if(a[i]<=a[i+1]){
                buy=i;
                sell=i+1;
                min=buy;
                break;
            }
        }
        if(buy!=-1){
            maxPro=a[sell]-a[buy];
            for(int i=sell+1;i<n;i++){
                if(a[i]<a[min]){
                    min=i;
                }else if(a[i]-a[min]>maxPro){
                    buy=min;
                    sell=i;
                    maxPro = a[sell]-a[buy];
                }
            }
        }
        return maxPro;
    }
};