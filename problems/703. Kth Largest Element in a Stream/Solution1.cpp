// Priority Queue
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq_;
    int k_;
    
    void pushPop(int val) {
        pq_.push(val);
        if (pq_.size() > k_) pq_.pop();
    }
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for (const auto& n: nums) pushPop(n);
        
    }
    
    int add(int val) {
        pushPop(val);
        return pq_.top();
    }
};
