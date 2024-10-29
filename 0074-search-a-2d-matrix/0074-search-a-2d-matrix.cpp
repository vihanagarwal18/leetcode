class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int total=n*m;
        int left=0;
        int right=total-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int x=mid/m;
            int y=mid%m;
            if(matrix[x][y]==target) return true;
            else if(matrix[x][y]>target){
                right=mid-1;
            }
            else left=mid+1;
        }
        return false;
    }
};