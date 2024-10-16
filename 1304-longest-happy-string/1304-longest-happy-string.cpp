class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string limit="222";
        string result="";
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        while(pq.size()>0){
            char c=pq.top().second;
            int freqleft=pq.top().first;
            pq.pop();
            int index=c-'a';
            if(limit[index]=='0'){
                if(pq.size()<=0) break;
                char cnext=pq.top().second;
                int frenext=pq.top().first;
                pq.pop();
                result+=cnext;
                frenext--;
                if(frenext>0){
                    pq.push({frenext,cnext});
                }
                pq.push({freqleft,c});
                int idx=cnext-'a';
                limit[idx]--;
                limit[index]='2';
            }
            else{
                result+=c;
                freqleft--;
                if(freqleft>0){
                    pq.push({freqleft,c});
                }
                limit[index]--;
            }
        }
        return result;
    }
};