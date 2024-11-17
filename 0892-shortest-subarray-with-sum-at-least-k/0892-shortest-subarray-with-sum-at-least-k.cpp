class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int result=INT_MAX;
        vector<long long> part_sum;
        part_sum.push_back(nums[0]);
        for(int i=1;i<n;i++){
            part_sum.push_back(part_sum[i-1]+nums[i]);
        }
        deque<int> dq; //doubel ended queue
        for(int i=0;i<n;i++){
            if(part_sum[i]>=k){
                result=min(result,i+1);
            }
            while(dq.size()>0 && part_sum[i]-part_sum[dq.front()] >=k){
                result=min(result,i-dq.front());
                dq.pop_front();
            }
            while(dq.size()>0 && part_sum[dq.back()]>=part_sum[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        if(result>n) return -1;
        return result;
    }
};