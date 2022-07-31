// BFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> cur{root};
        vector<TreeNode*> nex;
        int mx = -1e5, tmp, res = 1, layer = 1;
        while (cur.size()) {
            tmp = 0;
            for (auto& node: cur) {
                tmp += node->val;
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            if (tmp > mx) {
                mx = tmp;
                res = layer;
            }
            ++layer;
            cur = nex;
            nex = {};
        }
        return res;
   }
};
