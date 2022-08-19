var nextClosestTime = function(time) {
    
    const checkTime = (time) => {
        return time[2] < '6' && time[0] < '3' && (time[0] === '2' && time[1] < '4' || time[0] < '2') 
    };

    const dfs = (i, t) => {
        console.log(i, t);
        if (i === 4) {
            if (checkTime(t)) {
                const s = `${t[0]}${t[1]}:${t[2]}${t[3]}`;
                if (!min || s < min) min = s;
                if (s > time && s < res) res = s;
            }
        } else {
            for (let j of set) {
                dfs(i + 1, t + j);
            }
        }
    }

    const set = [];
    for (let i = 0; i < time.length; ++i) {
        if (time[i] !== ':' && !set.includes(time[i])) set.push(time[i]);
    }
    
    let res = '23:59';
    let min = null;
    dfs(0, "");
    return res === '23:59' ? min : res;
}

const test = '12:38';
console.log(nextClosestTime(test));
