class SmallestInfiniteSet {
public:
    set<int> pq;
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++){
            pq.insert(i);
        }
    }
    
    int popSmallest() {
        int result=*pq.begin();
        pq.erase(result);
        return result;
    }
    
    void addBack(int num) {
        pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */