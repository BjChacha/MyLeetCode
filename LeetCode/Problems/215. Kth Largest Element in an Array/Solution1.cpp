// quick-sort
class Solution {
private:
    int partition(vector<int>& nums, int l, int r, int k) {
        int t = rand() % (r - l + 1) + l;
        swap(nums[l], nums[t]);
        int m = l;
        for (int i = l + 1; i <= r; ++i) {
            if (nums[i] > nums[l]) swap(nums[i], nums[++m]);
        }
        swap(nums[m], nums[l]);
        if (m == k - 1) return nums[m];
        else if (m > k - 1) return partition(nums, l, m - 1, k);
        else return partition(nums, m + 1, r, k);
            
    }
    
    template <class T>
    void swap(T& a, T& b) {
        T tmp(move(a));
        a = move(b);
        b = move(tmp);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, k);
    }
};