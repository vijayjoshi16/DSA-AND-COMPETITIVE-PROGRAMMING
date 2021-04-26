class Solution {
public:
    int search(vector<int> &a,int target,int lo,int hi){
        if(lo>hi)
            return -1;
        int mid = lo+(hi-lo)/2;
        if(a[mid]==target)
            return mid;
        if(a[lo]<=a[mid]){
            if(target>=a[lo]&&target<=a[mid])
                return search(a,target,lo,mid);
            
                return search(a,target,mid+1,hi);
        }
        if(target>=a[mid]&&target<=a[hi])
            return search(a,target,mid,hi);
        return search(a,target,lo,mid-1);
    }
    
    int search(vector<int>& a, int target) {
        int n=a.size();
        return search(a,target,0,n-1);
    }
};