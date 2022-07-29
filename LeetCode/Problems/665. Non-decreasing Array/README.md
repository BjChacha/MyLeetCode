---
title: Non-decreasing Array
no: 665
difficulty: Medium
tags: [Array]
url: https://leetcode.com/problems/non-decreasing-array/
---

# 665. Non-decreasing Array

[LeetCode](https://leetcode.com/problems/non-decreasing-array/)

### 方法1. 贪心

- 检测当前元素比前者(`pre`)小的次数是否大于等于2次。问题关键是如何确定修改哪个元素（当前元素`nums[i]`还是前置元素`nums[i-1]`），即如何确定这个`pre`的值。
  1. 例如`[1，4, 2, 3]`，`2`比`4`小。此时只能把`4`改成`1`，即满足要求；
  2. 例如`[1，3, 2 ,4]`，`2`比`3`小。此时把`3`改成`1`或者把`2`改成，即满足要求;
  3. 例如`[3，4，1，2]`，此时不论修改哪个元素，都无法把数组改成非递减数组。
- 贪心实现：
  - 当当前元素`nums[i]`不比前前置元素`nums[i-2]`小，则没必要改当前元素，即`pre`为`nums[i-2]`，即 
  - 修改前置元素（例1），则赋值当前元素给`pre`；
  - 修改当前元素（例2），则不赋值当前元素给`pre`；
  