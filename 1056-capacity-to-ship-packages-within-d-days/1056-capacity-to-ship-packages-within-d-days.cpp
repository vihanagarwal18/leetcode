class Solution {
public:
    int countdays(vector<int>& weights, int capacity) {
        int result = 1; 
        int w= 0;
        for (int& p: weights) {
            if(p>capacity) return INT_MAX;
            if (w+p > capacity) {
                result++;
                w=p;
            } 
            else w+=p;
        }
        return result;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=1;
        long long right=0;
        for(auto& p:weights) right+=p;
        int result=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            int d=countdays(weights,mid);
            cout<<mid<<" "<<d<<endl;
            if(d>days){
                left=mid+1;
            }
            else{
                right=mid-1;
                result=min(result,mid);
            }
        }
        return result;
    }
};