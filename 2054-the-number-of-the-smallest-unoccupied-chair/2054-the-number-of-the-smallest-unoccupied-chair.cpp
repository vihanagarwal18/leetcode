class Solution {
public:
    struct comp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] > b[0];  
        }
    };
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<vector<int>,vector<vector<int>>,comp> person;
        for(int i=0;i<n;i++){
            vector<int> temp(3);
            temp[0]=times[i][0];
            temp[1]=times[i][1];
            temp[2]=i;
            person.push(temp); // {arrival, leaving, person index}
        }
        vector<int> chair(n,0);
        while(!person.empty()){
            int per=person.top()[2];
            auto arrival=person.top()[0];
            auto leaving=person.top()[1];
            person.pop();

            for(int i=0;i<n;i++){
                if(arrival>=chair[i]){
                    if(per==targetFriend) return i;
                    chair[i]=leaving;
                    break;
                }
            }
        }
        return -1;
    }
};