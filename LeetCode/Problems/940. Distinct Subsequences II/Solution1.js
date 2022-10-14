// dp
var distinctSubseqII = function(s) {
  const n = s.length;
  const mod = parseInt(1e9 + 7, 0);
  const preCount = new Array(26).fill(0);
  let cur = 1, nex, idx;
  for (let i = 0; i < n; ++i) {
    idx = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
    nex = cur;
    cur = (cur + nex - preCount[idx] + mod) % mod;
    preCount[idx] = nex;
  }
  return cur - 1;
};
