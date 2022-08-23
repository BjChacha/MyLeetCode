---
title: Permutations
no: 46
difficulty: Medium
tags: [Array, Backtracking]
url: https://leetcode.com/problems/permutations/
---

# 46. Permutations

[LeetCode](https://leetcode.com/problems/permutations/)

## Solution 1. Recursion

- 用组合数学的角度看问题：相当于有`n`个空位置，分别填入`n`个不同的数字，其中每个数字只能填一次；
- 直观的思路，用`visited`数组来标记数字有没有被填入。但这里用了取巧的方法：填过的数字在左边；未填的数字在右边。因此每选择一个数字填入，都把该数字交换到当前遍历的位置`swap(nums[i], nums[begin])`；
