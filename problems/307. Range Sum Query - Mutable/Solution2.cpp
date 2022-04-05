// Segment Tree

class NumArray {
private:
    int* tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = new int[2*n];
        for (int i = n; i < 2 * n; ++i) 
            tree[i] = nums[i-n];
        for (int i = n - 1; i > 0; --i) 
            tree[i] = tree[i*2] + tree[i*2+1];
    }
    
    void update(int index, int val) {
        int i = index + n;
        int diff = val - tree[i];
        while (i > 0) {
            tree[i] += diff;
            i /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        int l = left + n, r = right + n, sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum += tree[l];
                ++l;
            }
            if (r % 2 == 0) {
                sum += tree[r];
                --r;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};