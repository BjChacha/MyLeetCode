// simulate
var calPoints = function(ops) {
    let record = [];
    for (let c of ops) {
        switch(c) {
            case 'C':
                record.pop();
                break;
            case 'D':
                record.push(record[record.length-1] * 2);
                break;
            case '+':
                record.push(record[record.length-1] + record[record.length-2]);
                break;
            default:
                record.push(parseInt(c))
        }
    }
    return record.reduce((x, y)=>x + y);
};