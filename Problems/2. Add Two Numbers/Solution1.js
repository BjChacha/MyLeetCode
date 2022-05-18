// two pointers
var addTwoNumbers = function(l1, l2) {
    const dummy = new ListNode(-1);
    let cur = dummy;
    let sum = 0, carry = 0;
    while (l1 && l2) {
        sum = l1.val + l2.val + carry;
        cur.next = new ListNode(sum % 10);
        carry = sum > 9 ? 1 : 0;
        l1 = l1.next;
        l2 = l2.next;
        cur = cur.next;
    }
    while (l1) {
        sum = l1.val + carry;
        cur.next = new ListNode(sum % 10);
        carry = sum > 9 ? 1 : 0;
        l1 = l1.next;
        cur = cur.next;
    }
    while (l2) {
        sum = l2.val + carry;
        cur.next = new ListNode(sum % 10);
        carry = sum > 9 ? 1 : 0;
        l2 = l2.next;
        cur = cur.next;
    }
    if (carry) cur.next = new ListNode(1);
    return dummy.next;
};