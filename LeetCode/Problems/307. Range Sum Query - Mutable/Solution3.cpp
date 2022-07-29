// BIT (Binary Indexed Tree)
class NumArray {
private:
    int n;
    int* bit;
    vector<int> arr;
    
    int prefixSum(int index) {
        index += 1;
        int res = 0;
        while (index > 0) {
            res += bit[index];
            index -= (index & -index);
        }
        return res;
    }
    
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit = new int[n+1];
        arr = nums;
        
        for (int i = 0; i < n; ++i) bit[i+1] = nums[i];
        for (int i = 1; i <= n; ++i) {
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }
    
    void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;
        index += 1;
        
        while (index <= n) {
            bit[index] += delta;
            index += (index & -index);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};