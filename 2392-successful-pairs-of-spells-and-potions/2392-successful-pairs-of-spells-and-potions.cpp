class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<pair<int,int>> spellsindex;
        for(int i=0;i<n;i++){
            spellsindex.push_back({spells[i],i});
        }
        sort(potions.begin(),potions.end());
        sort(spellsindex.begin(),spellsindex.end());
        vector<int> result(n,0);
        int right=m-1;
        for(int i=0;i<n;i++){
            while(right>=0 && (long long) potions[right]*spellsindex[i].first >=success){
                right--;
            }
            int index=spellsindex[i].second;
            result[index]=m-right-1;
        }
        return result;
    }
};