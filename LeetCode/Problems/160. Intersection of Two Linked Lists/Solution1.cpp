class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        while(node1 && node2 && node1 != node2){
            node1 = node1->next;
            node2 = node2->next;
            
            if(node1 == node2) return node1;
            
            if(!node1) node1 = headB;
            if(!node2) node2 = headA;
        }
        return node1;
    }
};