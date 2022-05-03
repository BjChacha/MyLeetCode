// recurse
var verifyPostorder = function(postorder) {

    const helper = function(left, right) {
        if (left >= right) return true;

        let root = postorder[right];
        let k = left;

        // finding first element that is greater than root value
        while (k < right && postorder[k] < root) ++k;

        for (let i = k; i < right; ++i) {
            if (postorder[i] < root) return false;
        }

        return helper(left, k - 1) && helper(k, right - 1);
    }
    
    if (postorder.length < 2) return true;
    return helper(0, postorder.length - 1);
};