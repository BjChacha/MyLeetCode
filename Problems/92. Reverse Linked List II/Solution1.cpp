// traverse
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        for (int i = 1; i < left; ++i) pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* nex;
        for (int i = left; i < right; ++i) {
            nex = cur->next;
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
        }
        return dummy->next;
    }
};