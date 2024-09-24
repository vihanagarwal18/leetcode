class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        if(k>=n){
            int temp =max_element(skills.begin(),skills.end())-skills.begin();
            return temp;
        }
        int first=0;
        int last=1;
        unordered_map<int,int> m;//index wins
        while(true){
            if(skills[first]>skills[last]){
                m[first]++;
                if(m[first]==k) return first;
                last=(last+1)%n;
                if(last==first) last++;
            }
            else{
                m[last]++;
                first=last;
                if(m[last]==k) return last;
                last=(last+1)%n;
                if(last==first) last++;
            }

        }
        return -1;
    }
};