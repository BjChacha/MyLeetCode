---
title: House Robber
no: 198
difficulty: Medium
tags: [Array, Dynamic Programming]
url: https://leetcode.com/problems/house-robber/
---

# 198. House Robber

[Leetcode](https://leetcode.com/problems/house-robber/)

### 方法1. 动态规划

需要注意的是`dp[1] = max(nums[0], nums[1])`而不是`num[1]`，因为这题的转移方程中，`dp[i]`表示打劫到第`i`家时能偷窃到的最高金额。

