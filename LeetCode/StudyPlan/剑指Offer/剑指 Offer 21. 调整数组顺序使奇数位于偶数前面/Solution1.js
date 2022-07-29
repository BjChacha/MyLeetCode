// simulate
var exchange = function(nums) {
    let odds = [], evens = [];
    for (let num of nums) {
        num % 2 === 0 ? evens.push(num) : odds.push(num); 
    }
    odds.push(...evens);
    return odds;
};