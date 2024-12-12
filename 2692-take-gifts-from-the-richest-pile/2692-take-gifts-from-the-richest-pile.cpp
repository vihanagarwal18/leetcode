class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int> pq(gifts.begin(),gifts.end());
        while(k>0){
            long long temp=sqrt(pq.top());
            pq.pop();
            pq.push(temp);
            k--;
        }
        long long result=0;
        while(pq.size()>0){
            result+=pq.top();
            pq.pop();
        }
        return result;
    }
};