class MyCalendarTwo {
public:
    vector<vector<int>> singleevents; //start end
    vector<vector<int>> doubleevents; //start end
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (auto& event : doubleevents) {
            if (max(start, event[0]) < min(end, event[1])) {
                return false;
            }
        }
        for (auto& event : singleevents) {
            if (max(start, event[0]) < min(end, event[1])) {
                int s = max(start, event[0]);
                int e = min(end, event[1]);
                doubleevents.push_back({s, e});
            }
        }
        singleevents.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */