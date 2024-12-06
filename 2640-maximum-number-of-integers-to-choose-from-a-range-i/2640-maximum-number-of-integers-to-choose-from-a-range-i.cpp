class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int index=0;
        int result=0;
        unordered_set<int> u(banned.begin(),banned.end());
        for(int i=1;i<=n;i++){
            if(u.find(i)==u.end()){
                if(i>maxSum) break;
                maxSum-=i;
                result++;
            }
        }
        return result;
    }
};