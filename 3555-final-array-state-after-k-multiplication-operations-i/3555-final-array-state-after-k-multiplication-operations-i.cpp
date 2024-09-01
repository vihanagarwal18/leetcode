class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<>> pq;
        int i=0;
        for(auto& p:nums){
            pq.push({p,i});
            i++;
        }
        while(k>0){
            k--;
            auto p=pq.top();
            pq.pop();
            p.first*=multiplier;
            pq.push(p);
        }
        while(!pq.empty()){
            auto t=pq.top();
            int index=t.second;
            nums[index]=t.first;
            pq.pop();
        }
        return nums;
    }
};