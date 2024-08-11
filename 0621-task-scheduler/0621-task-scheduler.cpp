class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>freq;
        for(auto&task : tasks) freq[task]++;
        priority_queue<int> maxHeap;
        for(auto&p : freq){
            maxHeap.push(p.second); //sabse badi freq first
        }
        int cycles = 0;
        while(!maxHeap.empty()) {
            vector<int>temp;
            for (int i = 0; i <= n; i++){
                if(!maxHeap.empty()){
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }
            for(auto&count : temp){
                count--;
                if(count > 0){ 
                    maxHeap.push(count);
                }
            }
            if(maxHeap.empty()){   
                cycles+=temp.size();
            }
            else{ 
                cycles+=(n+1);//wait add krdiya 
            }
        }
        return cycles;
    }
};