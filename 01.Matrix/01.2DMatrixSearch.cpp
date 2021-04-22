// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l=0,h=m-1,mid;
        while(l<=h){
            mid = (l+h)/2;
            if(matrix[mid][0]<=target&&matrix[mid][n-1]>=target){
                int lo=0,hi=n-1,md;
                while(lo<=hi){
                    md=(lo+hi)/2;
                    if(matrix[mid][md]==target){
                        return true;
                    }else if(matrix[mid][md]>target){
                        hi=md-1;
                    }else{
                        lo=md+1;
                    }
                }
                return false;
            }else if(matrix[mid][0]>target){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
        
    }
}; 