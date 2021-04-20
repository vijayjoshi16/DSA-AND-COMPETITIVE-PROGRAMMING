class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int t=n/3;
        int c1=0,c2=0,e1=INT_MAX,e2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==e1)
                c1++;
            else if(nums[i]==e2)
                c2++;
            else if(c1==0){
                c1=1;
                e1=nums[i];
            }else if(c2==0){
                c2=1;
                e2=nums[i];
            }else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1)
                c1++;
            else if(nums[i]==e2)
                c2++;
        }
        if(c1>t)
            ans.push_back(e1);
        if(c2>t)
            ans.push_back(e2);
        return ans;
    }
};