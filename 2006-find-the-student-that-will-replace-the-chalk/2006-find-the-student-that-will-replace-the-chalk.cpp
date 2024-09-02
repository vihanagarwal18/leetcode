class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int index=0;
        int n=chalk.size();
        long long total=0;
        for(auto& p:chalk){
            total+=p;
        }
        k=k%total;
        while(k>=0){
            int require=chalk[index%n];
            if(k<require){
                return index%n;
            }
            index++;
            k-=require;
        }
        return -1;
    }
};