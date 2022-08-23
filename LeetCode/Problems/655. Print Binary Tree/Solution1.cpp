// simulation
class Solution {
private:
    void helper(vector<vector<string>>& matrix, TreeNode* node, int depth, int left, int right) {
        if (!node) return;
        int m = (left + right) >> 1;
        matrix[depth][m] = to_string(node->val);
        helper(matrix, node->left, depth + 1, left, m - 1);
        helper(matrix, node->right, depth + 1, m + 1, right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = 0;
        vector<TreeNode*> cur{root};
        vector<TreeNode*> nex;
        while (!cur.empty()) {
            depth ++;
            for (const auto& node: cur) {
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            cur = nex;
            nex = {};
        }
        int width = pow(2, depth) - 1;
        vector<vector<string>> res(depth, vector<string>(width, ""));
        helper(res, root, 0, 0, width - 1);
        return res;
    }
};
