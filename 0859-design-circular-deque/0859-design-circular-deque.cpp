class MyCircularDeque {
public:
    vector<int> array;
    int size;
    int front;
    int rear;
    int count; // no. of elements

    MyCircularDeque(int k) {
        array=vector<int>(k);
        size=k;
        front=0;
        rear=k-1;
        count=0; 
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + size) % size; // move front backward
        array[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % size; // move rear forward
        array[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front=(front+1)%size; // move front forward
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear =(rear-1+size)%size; // move rear backward
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return array[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return array[rear];
    }

    bool isEmpty() {
        return count==0;
    }

    bool isFull() {
        return count==size;
    }
};


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */