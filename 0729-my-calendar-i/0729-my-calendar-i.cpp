class MyCalendar {
public:
    vector<vector<int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& event : events) {
            if (max(start, event[0]) < min(end, event[1])) {
                return false;
            }
        }
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */