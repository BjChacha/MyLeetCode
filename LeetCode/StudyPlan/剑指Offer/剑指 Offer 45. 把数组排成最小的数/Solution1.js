// custom sorting
var minNumber = function(nums) {
    let arr = nums.map((x) => String(x));
    arr.sort((a, b) => parseInt(a+b) - parseInt(b+a));
    return arr.join("");
};