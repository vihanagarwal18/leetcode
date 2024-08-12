class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> q;
    int r=1;
    KthLargest(int k, vector<int>& nums) {
        r=k;
        priority_queue<int,vector<int>, greater<int>> qq(nums.begin(),nums.end());
        while(qq.size()>k){
            qq.pop();
        }
        q=qq;
    }
    int add(int val) {
        q.push(val);
        while(q.size()>r) q.pop();
        return q.top();   
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */