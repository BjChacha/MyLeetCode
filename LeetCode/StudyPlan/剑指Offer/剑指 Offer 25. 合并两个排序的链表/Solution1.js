// two pointers
var mergeTwoLists = function(l1, l2) {
    const dummy = new ListNode();
    let p = dummy;
    while (l1 && l2) {
        if (l1.val < l2.val) {
            p.next = l1;
            l1 = l1.next;
        } else {
            p.next = l2;
            l2 = l2.next;
        }
        p = p.next;
    }
    while (l1) {
        p.next = l1;
        l1 = l1.next;
        p = p.next;
    }
    while (l2) {
        p.next = l2;
        l2 = l2.next;
        p = p.next;
    }
    return dummy.next;
};