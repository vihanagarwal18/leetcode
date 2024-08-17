class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        multiset<int>u(people.begin(), people.end());
        int count=0;
        while(!u.empty()){
            auto s=u.begin();
            auto l=prev(u.end());
            if(*s+*l<=limit && s!=l){
                u.erase(s);
            }
            u.erase(l);
            count++;
        }
        return count;        
    }
};