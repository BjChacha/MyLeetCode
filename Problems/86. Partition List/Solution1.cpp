// 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy1 = new ListNode();
        ListNode *dummy2 = new ListNode();
        ListNode *dummy3 = new ListNode();
        ListNode *cur = head, *cur1 = dummy1, *cur2 = dummy2;
        while (cur) {
            if (cur->val < x) {
                cur1->next = cur;
                cur1 = cur1->next;
            } else {
                cur2->next = cur;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        cur1->next = dummy2->next;
        cur2->next = nullptr;

        return dummy1->next;
    }
};