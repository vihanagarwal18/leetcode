class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        priority_queue<pair<double,int> ,vector<pair<double,int>>,greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push({(double)dist[i]/speed[i],i}); //time ,index
        }
        int time=1;
        int result=1;
        pq.pop(); //first monster would be killed in startign only
        while(pq.size()>0){
            auto p=pq.top();
            if(p.first>time){
                time++;
                pq.pop();
                result++;
            }
            else return result;
        }
        return result;
    }
};