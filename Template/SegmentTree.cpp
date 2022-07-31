class NumArray {
private:
    int n;
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr = vector<int>(2*n);
        for (int i = n; i < 2 * n; ++i) arr[i] = nums[i-n];       
        for (int i = n - 1; i >= 0; --i) arr[i] = arr[i*2] + arr[i*2+1];
    }
    
    void update(int index, int val) {
        index += n;
        int diff =  val - arr[index];
        while (index) {
            arr[index] += diff;
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                sum += arr[left++];
            }
            if (right % 2 == 0) {
                sum += arr[right--];
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};
