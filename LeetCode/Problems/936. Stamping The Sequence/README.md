---
title: Stamping The Sequence
no: 936
difficulty: Hard
tags: [String, Stack, Greedy, Queue]
url: https://leetcode.com/problems/stamping-the-sequence/
---

# 936. Stamping The Sequence

[LeetCode](https://leetcode.com/problems/stamping-the-sequence/)

## Solution 1. String Match

- 用倒推的方法，在`target`中查找`stamp`字符串。查找规则如下：
  - `target`中的`?`字符可匹配任意字符，但匹配时不能全是`?`；
  - 每次匹配成功，都在`target`相应位置标记成`?`。
- 假设`target`长度为`m`，`stamp`长度为`n`，因此时间复杂度是`O(mn)`
- 这个方法的弊端在于*求出的序列未必是最优（最短）的*。
  - 虽然该方法AC了，但由于未证出*存在最优序列长度小于等于`10*m`的情况下存在另一个解长度大于`10*m`*，因此该方法不一定是正确解。
