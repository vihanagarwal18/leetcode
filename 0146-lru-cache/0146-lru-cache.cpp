class LRUCache {
public:
    int capacity;
    list<int> lrulist; //doubly linked list for tracking recency
    unordered_map<int,pair<int,list<int>::iterator>> m; //map for tracking key and value pair
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        auto lruiterator=m.find(key);
        if(lruiterator==m.end()){
            return -1;
        }
        int value=lruiterator->second.first;
        makerecent(key);//as just been used
        return value;
    }
    
    void put(int key, int value) {
        auto lruiterator=m.find(key);
        if(lruiterator==m.end()){
            //new task
            lrulist.push_front(key);
            pair<int,list<int>::iterator> lrumapval(value,lrulist.begin());
            m[key]=lrumapval;
        }
        else{
            //old task
            int& val=lruiterator->second.first;
            val=value;
        }
        makerecent(key);
    }
    void makerecent(int key){
        auto mapiterator=m.find(key);
        int value=mapiterator->second.first;
        auto lrulistiterator=mapiterator->second.second;
        lrulist.erase(lrulistiterator);
        lrulist.push_front(key);

        pair<int,list<int>::iterator> lrumapval(value,lrulist.begin());
        m[key]=lrumapval;

        if(lrulist.size()>capacity){
            auto lrulistlastiterator=--lrulist.end();
            int lrulastkey=*lrulistlastiterator;
            lrulist.pop_back();
            m.erase(lrulastkey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */