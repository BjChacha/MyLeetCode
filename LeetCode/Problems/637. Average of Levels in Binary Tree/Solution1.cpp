// layer order
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        vector<TreeNode*> cur, nex;
        cur.push_back(root);
        double sm, cnt;
        while (cur.size()) {
            sm = 0, cnt = 0;
            for (const auto& node: cur) {
                sm += node->val;
                cnt += 1;
                if (node->left) nex.push_back(node->left);
                if (node->right) nex.push_back(node->right);
            }
            res.push_back(sm / cnt);
            cur = nex;
            nex = {};
        }
        return res;
    }
};
