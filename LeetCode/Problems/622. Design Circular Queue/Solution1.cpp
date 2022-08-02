// circle queue
class MyCircularQueue {
private:
    vector<int> cache;
    int size, head, tail;
public:
    MyCircularQueue(int k) {
        cache = vector<int>(k, -1);
        size = k;
        // head: the current position of queue head
        // tail: the next position of queue tail;
        head = 0, tail = 0;;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        cache[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        cache[head] = -1;
        head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        return cache[head];
    }
    
    int Rear() {
        return cache[(tail+size-1)%size];
    }
    
    bool isEmpty() {
        return head == tail && cache[head] == -1;
    }
    
    bool isFull() {
        return head == tail && cache[head] >= 0;
    }
};
