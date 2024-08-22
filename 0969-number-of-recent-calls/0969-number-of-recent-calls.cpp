class RecentCounter {
public:
    deque<pair<int,int>> q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while( q.empty()==false && t-3000>q.back().second){
            q.pop_back();
        }
        q.push_front({t-3000,t});
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */