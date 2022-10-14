// next permutation
var nextGreaterElement = function(N) {
  const arr = ('' + N).split('').map(i => +i);
  const n = arr.length;
  let i = n - 2;
  // find the first smaller element from right to left
  while (i >= 0 && arr[i] >= arr[i + 1]) --i;
  if (i < 0) return -1;

  let j = n - 1;
  // find the first 
  while (arr[j] <= arr[i]) --j;
  // swap i-th and j-th element
  let tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
  // sort the (i, j] range of arr
  arr.splice(i + 1, n - i, ...arr.slice(i + 1, n).sort());
  const res = +(arr.join(''));
  return res < 2 ** 31 ? res : -1;
};
