class MyCircularDeque {
private:
    vector<int> q;
    int n, mx;
public:
    MyCircularDeque(int k) {
        n = 0;
        mx = k;
    }
    
    bool insertFront(int value) {
        if (n < mx) {
            q.insert(q.begin(), value);
            ++n;
            return true;
        } else {
            return false;
        }
    }
    
    bool insertLast(int value) {
        if (n < mx) {
            q.push_back(value);
            ++n;
            return true;
        } else {
            return false;
        }
    }
    
    bool deleteFront() {
        if (n > 0) {
            q.erase(q.begin());
            --n;
            return true;
        } else {
            return false;
        }
    }
    
    bool deleteLast() {
        if (n > 0) {
            q.pop_back();
            --n;
            return true;
        } else {
            return false;
        }
    }
    
    int getFront() {
        return n > 0 ? q[0] : -1;

    }
    
    int getRear() {
        return n > 0 ? q[n-1] : -1;
    }
    
    bool isEmpty() {
        return n == 0;
    }
    
    bool isFull() {
        return n == mx;
    }
};
