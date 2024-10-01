class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto & p:arr){
            if(p<0){
                p=p%k +k; // -7%5 gives -2 add k one more time
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