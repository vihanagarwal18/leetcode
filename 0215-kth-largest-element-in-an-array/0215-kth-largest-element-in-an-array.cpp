class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int> ,greater<int>> q;
        for(auto& p:nums){
            q.push(p);
            if(q.size()>k){
                q.pop();
            }
        }
        // while(q.size()>k){
        //     q.pop();
        // }
        return q.top();
    }
};