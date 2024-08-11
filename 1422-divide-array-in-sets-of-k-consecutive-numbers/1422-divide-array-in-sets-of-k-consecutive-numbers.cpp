class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        priority_queue<int,vector<int>, greater<int>> q(nums.begin(),nums.end());
        unordered_map<int,int> m;
        for(auto& p:nums){
            m[p]++;
        }
        while(!q.empty()){
            int first=q.top();
            q.pop();
            if(m[first]==0) continue;
            for(int i=0;i<k;i++){
                int nextnumber=first+i;
                if(m[nextnumber]==0) return false;
                m[nextnumber]--;
            }
        }
        return true;
    }
};