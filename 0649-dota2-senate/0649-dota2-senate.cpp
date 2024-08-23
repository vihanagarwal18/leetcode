class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        for(int i=0;i<n;i++) {
            if(senate[i]=='R') radiant.push(i); //chota phele hee ayega
            else dire.push(i);
        }
        while(!radiant.empty() && !dire.empty()) {   
            if(radiant.front()<dire.front()) {
                radiant.push(radiant.front() + n);//ye jyda strong toh ye dire ka senate kha jayega
            } 
            else dire.push(dire.front() + n);
            radiant.pop();
            dire.pop();
        }
        if(radiant.empty()) return "Dire";
        return "Radiant";
    }
};