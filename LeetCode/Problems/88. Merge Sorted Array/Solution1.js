// two pointers
var merge = function(nums1, m, nums2, n) {
    let p1 = m - 1, p2 = n - 1;
    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] < nums2[p2]) nums1[p1+p2+1] = nums2[p2--];
        else nums1[p1+p2+1] = nums1[p1--];
    }
    while (p2 >= 0) nums1[p1+p2+1] = nums2[p2--];
    return ;
};