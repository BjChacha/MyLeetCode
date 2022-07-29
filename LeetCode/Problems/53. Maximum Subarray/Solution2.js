// divide and conquer
var maxSubArray = function(nums) {
    
    const helper = function(left, right) {
        if (left === right) return nums[left];
        
        let mid = (left + right) >>> 1;
        
        let leftPart = helper(left, mid);
        let rightPart = helper(mid + 1, right);
        
        let midLeft = nums[mid], sm = nums[mid];
        for (let i = mid - 1; i >= left; --i) {
            sm += nums[i];
            midLeft = Math.max(midLeft, sm);
        }
        let midRight = nums[mid+1]
        sm = nums[mid+1];
        for (let i = mid + 2; i <= right; ++i) {
            sm += nums[i];
            midRight = Math.max(midRight, sm);
        }
        let midPart = midLeft + midRight;
        
        return Math.max(leftPart, midPart, rightPart);
    }
    
    return helper(0, nums.length - 1);
};