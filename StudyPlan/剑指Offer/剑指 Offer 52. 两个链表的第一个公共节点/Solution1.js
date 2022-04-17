// two pointer
var getIntersectionNode = function(headA, headB) {
    if (!headA || !headB) return null;
    let p1 = headA, p2 = headB, cnt = 0;
    while (cnt < 3) {
        if (p1 == p2) return p1;
        p1 = p1.next;
        p2 = p2.next;
        if (!p1) p1 = headB, ++cnt;
        if (!p2) p2 = headA, ++cnt;
    }
    return null;
};