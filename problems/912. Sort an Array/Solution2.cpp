// 快速排序-双边扫描
class Solution {
private:
    void quickSort(vector<int>& nums, int l, int u) {
        if (l >= u) return;

        // swap(nums[l], nums[l+(u-l)/2]);
        swap(nums[l], nums[rand()%(u-l+1)+l]);
        
        int t = nums[l], i = l, j = u + 1;
        while (i < j) {
            do ++i; while (i <= u && nums[i] < t);
            do --j; while (nums[j] > t);
            if (i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[j]);
        quickSort(nums, l, j - 1), quickSort(nums, j + 1, u);
    }
    
    void swap(int& a, int&b) {
        int tmp(move(a));
        a = move(b);
        b = move(tmp);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};