var buildTree = function(inorder, postorder) {

    const dfs = function(l, r) {
        if (l > r) return null;
        const value = postorder[i--];
        const m = inorder.indexOf(value);
        const right = dfs(m + 1, r);
        const left = dfs(l, m - 1);
        return new TreeNode(value, left, right);
    }

    let i = postorder.length - 1;
    return dfs(0, i);
};
