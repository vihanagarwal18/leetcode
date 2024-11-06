class Solution {
public:
    int countsetbits(int num) {
        int count = 0;
        while (num) {
            count += (num & 1);
            num >>= 1;
        }
        return count;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        int setbits=countsetbits(nums[0]);
        vector<pair<int,int>> vect;
        int index=0;
        for(int i=1;i<n;i++){
            int temp=countsetbits(nums[i]);
            if(temp!=setbits){
                vect.push_back({index,i-1});
                setbits=temp;
                index=i;
            }
            if(i==n-1){
                vect.push_back({index,n-1});
            }
        }
        int m=vect.size();
        for(int i=1;i<m;i++){
            int smaller=*max_element(nums.begin()+vect[i-1].first, nums.begin()+vect[i-1].second+1);
            int larger=*min_element(nums.begin()+vect[i].first, nums.begin()+vect[i].second+1);
            if(smaller>larger) return false;
        }
        return true;
    }
};