// 使用栈，先进后出
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        vector<int> res;
        ListNode* cur = head;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};