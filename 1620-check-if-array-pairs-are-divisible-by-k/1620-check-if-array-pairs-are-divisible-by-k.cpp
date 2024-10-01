class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //odd +odd is even
        //even + odd is odd
        //even +even is even
        unordered_map<int,int> m;
        for(auto & p:arr){
            if(p<0){
                while(p<0){
                    p+=k;
                }
            }
            int temp=p%k;
            m[temp]++;
        }
        for(int i=1;i<k;i++){
            if(m[i]!=m[k-i]) return false;
        }
        //check for i=0
        if(m[0]>0 && m[0]%2!=0) return false;
        return true;
    }
};