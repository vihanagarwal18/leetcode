class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        vector<int> bitscount(25,0);
        for(auto& p:candidates){
            int index=0;
            while(p>0){
                if(p&1==1)  bitscount[index]++;
                p=p>>1;
                index++;
            }
        }
        int maxx=0;
        for(auto& p:bitscount){
            if(p>maxx) maxx=p;
        }
        return maxx;

    }
};