// simulate?
var isBipartite = function(graph) {
    const n = graph.length;
    if (n === 0) return false;
    const visited = new Array(n).fill(-1);
    visited[0] = 1;
    const s1 = [0], s2 = [];
    let i1 = 0, i2 = 0, added = true;
    
    while (added) {
        added = false;
        while (i1 < s1.length) {
            for (let j of graph[s1[i1]]) {
                if (visited[j] == 1) return false;
                if (visited[j] < 0) {
                    s2.push(j);
                    visited[j] = 2;
                    added = true;
                }
            }
            ++i1;
        }
        
        while (i2 < s2.length) {
            for (let j of graph[s2[i2]]) {
                if (visited[j] == 2) return false;
                if (visited[j] < 0) {
                    s1.push(j);
                    visited[j] = 1;
                    added = true;
                }
            }
            ++i2;
        }
        
        if (!added) {
            for (let i = 0; i < n; ++i) {
                if (visited[i] < 0) {
                    s1.push(i);
                    visited[i] = 1;
                    added = true;
                    break;
                }
            }
        }
    }
    return true;
};