// quicksort
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
 var getLeastNumbers = function(arr, k) {
    
    const partition = function(left, right) {

        if (left >= right) return;

        const pivot = Math.floor(Math.random() * (right - left + 1) + left);
        swap(left, pivot);

        let mid = left;
        for (let i = left + 1; i <= right; ++i) {
            if (arr[i] < arr[left]) swap(++mid, i);
        }
        swap(left, mid);
        
        if (mid < k) partition(mid + 1, right);
        else if (mid > k) partition(left, mid - 1);
    }

    const swap = function(i, j) {
        let tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    partition(0, arr.length - 1);
    return arr.slice(0, k);
};