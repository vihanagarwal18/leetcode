//using map and doubly linked list

class LFUCache {
public:
    class Node{
    public:
        //double linked list with 3 values for each node
        int key;
        int value;
        int count;
        Node* prev;
        Node* next;

        Node(int key,int value,int cnt){
            this->key=key;
            this->value=value;
            count=cnt;
            prev=NULL;
            next=NULL;
        }
    };

    int capacity;
    Node* head=new Node(-1,-1,INT_MAX);
    Node* tail=new Node(-1,-1,0);
    unordered_map<int,Node*> m;

    void addnode(Node* newnode){
        Node* pos=head; 
        while(pos->next->count > newnode->count){
            pos=pos->next;
        }
        Node* temp=newnode;
        Node* temp1=pos->next;

        pos->next=temp;
        temp->prev=pos;

        temp->next=temp1;
        temp1->prev=temp;
    }
    void deletenode(Node* delnode){
        Node* tempnext=delnode->next;
        Node* temp=delnode->prev;

        temp->next=tempnext;
        tempnext->prev=temp;
    }
    LFUCache(int capacity) {
        //initalization
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            //already present
            Node* temp=m[key];
            deletenode(m[key]);
            temp->count=temp->count+1; //is used one time thats why increase
            addnode(temp);
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        int frequency=0;
        if(m.find(key)!=m.end()){
            //already there
            frequency=m[key]->count;
            deletenode(m[key]);
        }
        else if(m.size()==capacity){
            m.erase(tail->prev->key);//least frequent one will be removed
            deletenode(tail->prev);
        }
        Node* newnode=new Node(key,value,frequency+1);
        addnode(newnode);
        m[key]=newnode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */