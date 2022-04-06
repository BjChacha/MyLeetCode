// 反转数组
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* cur = head;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};