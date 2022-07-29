// two pointers
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1.resize(m + n);
        --m, --n;
        while (m >= 0 && n >= 0) {
            if (nums2[n] >= nums1[m]) nums1[m+n+1] = nums2[n], --n;
            else nums1[m+n+1] = nums1[m], --m;
        }
        while (n >= 0) {
            nums1[m+n+1] = nums2[n], --n;
        }
        return ;
    }
};