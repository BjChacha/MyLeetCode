---
title: Shortest Subarray with Sum at Least K
no: 862
difficulty: Hard
tags: [Queue, Array, Binary Search, Prefix Sum, Sliding Window, Monotonic Queue, Heap (Priority Queue)]
url: https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/
---

# 862. Shortest Subarray with Sum at Least K

[LeetCode](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/)

## Solution1. 单调队列

- 首先，求连续数组和，可以用前缀和；
- 其次，数组元素内有*负数*，前缀和失去单调性，不能用**滑动窗口**来解决；
- 然后，用前缀和暴力解决，时间复杂度为$O(n^2)$，因此需要优化：
  1. 首先认为算法从左到右遍历前缀和数组`prefixSum`，且有一个数据结构来保存遍历历史信息；
  2. 当$sum([i, j)) = prefixSum[j] - prefixSum[i] >= k$，那么不存在$k > j$，使得$sum([i, k)) >= k$且$j - i > k - i$，即左端点`i`没有存留的必要；
  3. 当$i < j, prefixSum[j] <= prefixSum[i]$，那么若存在$k > j, sum([i, k)) >= k$，则必有$sum([j, k)) >= k$ 且 $k - j < k - i$，即右端点`i`没有存留的必要；
- 综上，2的优化是移除历史记录信息的**左侧**，而3的优化是移除历史记录信息的**右侧**，故1中需要的数据结构为**双端队列**，且3保证了队列的*单调递增性*；
