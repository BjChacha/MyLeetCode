// union set
const UnionSet = function(size) {
    this.root = new Array(size).fill(0).map((e, i) => i);
    this.rank = new Array(size).fill(1);
    this.groups = size;
}

UnionSet.prototype.find = function(x) {
    if (x === this.root[x]) return x;
    return this.root[x] = this.find(this.root[x]);
}

UnionSet.prototype.union = function(x, y) {
    let rootX = this.find(x);
    let rootY = this.find(y);
    if (rootX !== rootY) {
        if (this.rank[rootX] >= this.rank[rootY]) {
            this.root[rootY] = rootX;
            this.rank[rootX] += this.rank[rootY];
        } else{
            this.root[rootX] = rootY;
            this.rank[rootY] += this.rank[rootX];
        }
        --this.groups;
    }
}

UnionSet.prototype.connected = function(x, y) {
    return this.find(x) === this.find(y);
}

var findCircleNum = function(isConnected) {
    const n = isConnected.length;
    const us = new UnionSet(n);
    for (let i = 0; i < n - 1; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (isConnected[i][j]) us.union(i, j);
        }
    }
    return us.groups;
};