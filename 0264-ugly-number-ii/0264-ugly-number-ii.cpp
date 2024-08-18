class Solution {
public:
    int nthUglyNumber(int n) {
        int result=1;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        unordered_set<long long> u;
        u.insert(1);
        pq.push(1);
        while(n>0){
            auto it=pq.top();
            pq.pop();
            result=it;
            if(u.find(it*2)==u.end()) {
                pq.push(it*2);
                u.insert(it*2);
            }
            if(u.find(it*3)==u.end()) {
                pq.push(it*3);
                u.insert(it*3);
            }
            if(u.find(it*5)==u.end()) {
                pq.push(it*5);
                u.insert(it*5);
            }
            n--;
        }
        return result;
    }
};