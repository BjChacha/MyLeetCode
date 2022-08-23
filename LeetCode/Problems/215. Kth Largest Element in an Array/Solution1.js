// quick-sort
var findKthLargest = function(nums, k) {

    const swap = (i, j) => {
        const tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    };

    let l = 0, r = nums.length - 1;
    while (l <= r) {
        const p = Math.floor(Math.random() * (r - l + 1) + l);
        swap(l, p);
        
        let m = l;
        for (let i = l + 1; i <= r; ++i) {
            if (nums[i] > nums[l]) swap(++m, i);
        }
        swap(l, m);

        if (m === k - 1) return nums[m];
        else if (m > k - 1) r = m - 1;
        else l = m + 1;
    }
};
