---
title: Minimum Number of Refueling Stops
no: 871
difficulty: Hard
tags: [Array, Dynamic Programming, Greedy, Heap (Priority Queue)]
url: https://leetcode.com/problems/minimum-number-of-refueling-stops/
---

# 871. Minimum Number of Refueling Stops

[LeetCode](https://leetcode.com/problems/minimum-number-of-refueling-stops/)

## Solution 1. DP

- `dp[i]`的意义：在第`i`个station时可能拥有的*最大*`fuel`值；
- 因为是*最大*的，因此每遍历一个station，都要更新前面的`dp`值，因此时间复杂度是`O(n^2)`


## Solution 2. max heap

- 把问题看作“每经过一个加油站，把油桶带上；没油的时候，使用最大容量的油桶加油，直至没有备用燃料或者到达了终点”。这就成了一个最大堆问题。
