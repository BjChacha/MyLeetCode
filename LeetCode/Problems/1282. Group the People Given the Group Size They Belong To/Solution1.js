var groupThePeople = function(groupSizes) {
    const m = {};
    groupSizes.forEach((e, i) => {
        m[e] ? m[e].push(i) : m[e] = [i];
    });
    const res = [];
    for (let key in m) {
        for (let i = 0; i < m[key].length; i += +key) {
            res.push(m[key].slice(i, i + +key));
        }
    }
    return res;
};
