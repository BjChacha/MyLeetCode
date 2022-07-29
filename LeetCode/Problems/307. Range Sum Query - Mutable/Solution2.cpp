// Segment Tree
class NumArray {
private:
    int n;
    int* t;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        t = new int[n*2];
        for (int i = n; i < 2 * n; ++i) t[i] = nums[i-n];
        for (int i = n - 1; i > 0; --i) t[i] = t[i*2] + t[i*2+1];
    }
    
    void update(int index, int val) {
        index += n;
        int diff = val - t[index];
        while (index > 0) {
            t[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n, right += n;
        int res = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                res += t[left];
                ++left;
            }
            if (right % 2 == 0) {
                res += t[right];
                --right;
            }
            left /= 2, right /= 2;
        }
        return res;
    }
};