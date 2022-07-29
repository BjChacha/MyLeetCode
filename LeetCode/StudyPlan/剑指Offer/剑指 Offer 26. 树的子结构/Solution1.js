var isSubStructure = function(A, B) {
    if (!A || !B) return false;
    return A.val === B.val && checkStructure(A, B) || isSubStructure(A.left, B) || isSubStructure(A.right, B);
};

const checkStructure = function(a, b) {
    if (!b) return true;
    if (!a) return false
    return a.val === b.val && checkStructure(a.left, b.left) && checkStructure(a.right, b.right);
}