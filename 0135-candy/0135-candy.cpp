class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int> candy(n, 1);  

        // phele left neighbour ke sangh
        for (int i=1;i<n;i++) {
            if (rating[i]>rating[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        // ab right neighbour ke sangh
        for (int i=n-2;i>=0;i--) {
            if (rating[i]>rating[i+1]) {
                candy[i]=max(candy[i],candy[i+1]+1);
            }
        }
        int result=0;
        for (auto& c : candy) {
            result+=c;
        }
        return result;
    }
};
