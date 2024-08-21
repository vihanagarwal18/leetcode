class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=(n-1)*(min(height[0],height[n-1]));
        int left=0;
        int right=n-1;
        while(left<right){
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            int area=(right-left)*(min(height[left],height[right]));
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};