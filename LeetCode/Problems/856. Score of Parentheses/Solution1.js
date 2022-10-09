var scoreOfParentheses = function(s) {
  const stk = [0];
  for (let c of s) {
    if (c === '(') {
      stk.push(0);
    } else {
      let tmp = stk.pop() * 2;
      stk.push(stk.pop() + tmp + (tmp === 0));
    }
  }
  return stk[0];
};
