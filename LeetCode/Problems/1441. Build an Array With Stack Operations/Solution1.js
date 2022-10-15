var buildArray = function(target, n) {
  const opPush = 'Push';
  const opPop = 'Pop';
  const res = [];
  let cur = 1;
  for (let num of target) {
    while (cur < num) {
      res.push(opPush);
      res.push(opPop);
      cur++;
    }
    res.push(opPush);
    cur++;
  }
  return res;
};
