// 快速排序-单边扫描
class Solution {
private:
    void quickSort(vector<int>& nums, int l, int u) {
        if (l >= u) return;

        // swap(nums[l], nums[l+(u-l)/2]);
        swap(nums[l], nums[rand()%(u-l+1)+l]);
        
        int m = l;
        for (int i = l + 1; i <= u; ++i) {
            if (nums[i] < nums[l]) {
                swap(nums[i], nums[++m]);
            }
        }
        swap(nums[m], nums[l]);
        
        quickSort(nums, l, m - 1);
        quickSort(nums, m + 1, u);
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