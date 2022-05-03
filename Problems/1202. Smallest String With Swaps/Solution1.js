// union set
const UnionFind = function(size) {
    this.root = new Array(size).fill(0).map((e, i) => i);
    this.rank = new Array(size).fill(0).map((e, i) => i);
}

UnionFind.prototype.find = function(x) {
    if (x === this.root[x]) return x;
    return this.root[x] = find(this.root[x]);
}

UnionFind.prototype.unionSet(x, y) {
    let rootX = this.find(x);
    let rootY = this.find(y);
    if (rootX !== rootY) {
        if (rank[rootX] >= rank[rootY]) {
            root[rootY] = rootX;
            rank[rootX] += rank[rootY];
        } else {
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
}

var smallestStringWithSwaps = function(s, pairs) {
    const n = s.length;
    let uf = new UnionFind(n);
    pairs.array.forEach(p => uf.unionSet(p[0], p[1]));

    let rootToComponent = new Map();
    let root;
    for (let i = 0; i < n; ++i) {
        root = uf.find(i);
        if (!rootToComponent.has(root)) rootToComponent.set(root, []);
        rootToComponent.get(uf.find(i)).push(i);
    }
    let res = new Array(n);
    for (let component of rootToComponent) {
        let indices = components[1];
        let characters = indices.map((i) => s[i]);
        characters.sort();
        for (let i = 0; i < indices.length; ++i) {
            res[indices[i]] = characters[i];
        }
    }
    return res.join('');
};