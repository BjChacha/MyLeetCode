// sliding window
var totalFruit = function(fruits) {
  const collects = new Map();
  const n = fruits.length;
  let i = 0, j = 0;
  let res = 0
  while (j < n) {
    while (j < n && (collects.size < 2 || collects.has(fruits[j]))) {
      collects.set(fruits[j], (collects.has(fruits[j]) ? collects.get(fruits[j]) : 0) + 1);
      ++j;
    }
    res = Math.max(res, j - i);
    while (i < j && collects.size === 2) {
      collects.set(fruits[i], collects.get(fruits[i]) - 1);
      if (collects.get(fruits[i]) == 0) collects.delete(fruits[i]);
      ++i;
    }
  }
  return res;
};
