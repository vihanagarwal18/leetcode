class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxx=*max_element(piles.begin(),piles.end());
        int left=1;
        int right=maxx;
        int result=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            long long time=0;
            for(auto& p:piles){
                time+=ceil((double)p/mid);
            }
            if(time>h) left=mid+1;
            else{
                result=min(result,mid);
                right=mid-1;
            }
        }
        // if(result==INT_MAX) return -1;
        return result;
    }
};