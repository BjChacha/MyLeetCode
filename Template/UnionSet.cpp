class UnionSet {
private:
    vector<int> rank, root;
public:
    UnionSet(int size) {
        rank = vector<int>(size, 1);
        root = vector<int>(size);
        
        for (int i = 0; i < size; ++i) root[i] = i;
    }
    
    int find(int x) {
        int rootX = root[x];
        while (rootX != root[rootX]) {
            rootX = root[rootX];
        }
        return root[x] = rootX;
    }
    
    void un(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            } else {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            }
        }
    }
};