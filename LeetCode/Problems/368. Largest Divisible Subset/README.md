---
title: Largest Divisible Subset
no: 368
difficulty: Medium
tags: [Array, Math, Dynamic Programming, Sorting]
url: https://leetcode.com/problems/largest-divisible-subset/
---

# 368. Largest Divisible Subset

[LeetCode](https://leetcode.com/problems/largest-divisible-subset/)

## Solution 1. DP

- 可以看作“求最长整除子序列”；
- 求最长长度的话，单纯用dp就可以完成；
  - 转移方程，用Python的列表推导式大致为`dp[i] = max(dp[j] + i if nums[i] % nums[j] == 0 else 1 for j in range(0, i))`，不熟悉Python的话注意这里`range(0, i)`是左闭右开区间；
- 求最长子序列的具体序列是使这题更加复杂的主要原因。
  - 如果使用常见的路径搜索方法（如BFS、DFS），显然会增加额外的复杂度；
  - 这里我们使用一个反向链接bp，在计算dp的过程中更新，便于计算出最长子序列长度后能够马上通过反向推出具体序列元素。
