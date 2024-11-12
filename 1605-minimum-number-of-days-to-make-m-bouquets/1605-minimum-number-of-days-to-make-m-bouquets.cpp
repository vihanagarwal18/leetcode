class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // long long flowerneeded=m*k;
        int n=bloomDay.size();
        // if(flowerneeded>n) return -1;
        int left=0;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int result=INT_MAX;
        while(left<=right){
            int mid=left+(right-left)/2;
            int count=0;
            int flowerbloom=0;
            for(auto& p:bloomDay){
                if(p<=mid){
                    count++;
                    if(count==k) {
                        flowerbloom++;
                        count=0;
                    }
                }
                else count=0;
            }
            if(flowerbloom<m){
                left=mid+1;
            }
            else {
                result=min(result,mid);
                right=mid-1;
            }
        }
        if(result==INT_MAX) return -1;
        return result;

    }
};