// Divide nums into sqrt(n) groups
// Time complexity: init: O(n); update: O(1); sumRange: O(sqrt(n))
// Space complexity: 

class NumArray {
private:
    int bSize;
    vector<int> nums;
    vector<int> blocks;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        int b = (int)sqrt(n);
        for (int i = 0; i < n; i += b) {
            int sum = 0;
            for (int j = i; j < min(i + b, n); ++j) sum += nums[j];
            this->blocks.push_back(move(sum));
        }
        this->nums = nums;
        this->bSize = move(b);
    }
    
    void update(int index, int val) {
        this->blocks[index/this->bSize] += (val - this->nums[index]);
        this->nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int bLeft = left / this->bSize;
        int bRight = right / this->bSize;
        
        if (bLeft == bRight) {
            for (int i = left; i <= right; ++i) 
                sum += this->nums[i];
        } else {
            for (int i = left; i < (bLeft + 1) * this->bSize; ++i) 
                sum += this->nums[i];
            for (int i = bLeft + 1; i < bRight; ++i) 
                sum += this->blocks[i];
            for (int i = right; i >= bRight * this->bSize; --i) 
                sum += this->nums[i];
        }
            
        return sum;
    }
};