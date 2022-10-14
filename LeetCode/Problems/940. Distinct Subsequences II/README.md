---
title: Distinct Subsequences II
no: 940
difficulty: Hard
tags: [String, Dynamic Programming]
url: https://leetcode.cn/problems/distinct-subsequences-ii/
---

# 940. Distinct Subsequences II

[LeetCode](https://leetcode.cn/problems/distinct-subsequences-ii/)

## Solution 1. DP

- `dp[i]`为`[0, i]`范围内的子串数，有`dp[i] = dp[i-1] + newCount - reduplicatedCount`；
- 初始值`dp[0]=1`；新增数`newCount`为前序位置的非空子串数（即`dp[i-1]`）；重复数`reduplicatedCount`为前序位置非空子串中以`s[i]`结尾的个数；
