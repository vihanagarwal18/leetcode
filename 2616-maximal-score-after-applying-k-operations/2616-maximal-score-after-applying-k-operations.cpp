class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for(auto& p:nums){
            pq.push(p);
        }
        long long result=0;
        while(k>0){
            int a=pq.top();
            int t=ceil((double)a/3);
            result+=a;
            pq.pop();
            pq.push(t);
            k--;
        }
        return result;
    }
};