class Solution {
public:
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums2.size();
        vector<pair<int, int>> vect;    
        for (int i = 0; i < n; i++) {
            vect.push_back({nums2[i], nums1[i]});
        }
        sort(vect.begin(), vect.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long result = 0;
        for (int i=0;i<n;i++) {
            //vect[i].first is minimum
            sum+=vect[i].second;
            pq.push(vect[i].second);
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop(); // jab bhi size k se jyda hoga vo sabse chota element ko hata dega
            }
            if (pq.size() == k) {
                result=max(result,sum*vect[i].first);
            }
        }
        return result;
    }
};
