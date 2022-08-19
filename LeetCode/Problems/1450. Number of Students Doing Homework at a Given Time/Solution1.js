// simulation
var busyStudent = function(startTime, endTime, queryTime) {
    return startTime.map((s, i)=> s <= queryTime && queryTime <= endTime[i] ? 1 : 0).reduce((a, b) => a + b);
};
