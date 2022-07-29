// Binary search
var minArray = function(numbers) {
    let left = 0, right = numbers.length - 1, mid;
    while (left < right) {
        mid = left + right >>> 1;
        // console.log(left, mid, right);
        if (numbers[mid] < numbers[left]) right = mid;
        else if (numbers[mid] > numbers[right]) left = mid + 1;
        else right --;
    }
    return numbers[left];
};