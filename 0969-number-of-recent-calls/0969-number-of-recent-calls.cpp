class RecentCounter {
public:
    deque<pair<int,int>> q;
    RecentCounter() {
        q.push_front({-3000,0});
        q.pop_front();
    }
    
    int ping(int t) {
        // q.push_front({t-3000,t});
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