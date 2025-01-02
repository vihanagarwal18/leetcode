/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={-1,-1};
        int left=0;
        int right=nums.size()-1;
        int ptr=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                //check for first and last occurnce
                res[0]=mid;
                res[1]=mid;
                while(res[0]>-1 && nums[res[0]]==target){
                    res[0]--;
                }
                while(res[1]<nums.size() &&nums[res[1]]==target ){
                    res[1]++;
                }
                res[0]++;
                res[1]--;
                return res;
            }
            else if(nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return res;
    }
};*/

class Solution {
public:
    int binarysearch(vector<int>& nums,int& target,string s){
        int left=0;
        int right=nums.size()-1;
        int result=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                result=mid;
                if(s=="first"){
                    right=mid-1;
                }
                else left=mid+1;
            }
            else if(nums[mid]>target) right=mid-1;
            else left=mid+1;
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        vector<int> result={-1,-1};
        result[0]=binarysearch(nums,target,"first");
        result[1]=binarysearch(nums,target,"second");
        return result;
    }
};