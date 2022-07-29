---
title: Remove Palindromic Subsequences
no: 1332
difficulty: Easy
tags: [Two Pointers, String]
url: https://leetcode.com/problems/remove-palindromic-subsequences/
---

# 1332. Remove Palindromic Subsequences

[LeetCode](https://leetcode.com/problems/remove-palindromic-subsequences/)

### 方法1：双指针

1. 判断整个字符串`s`是否为回文串，若是则返回`1`，若否则返回`2`；
2. 为何返回`2`：第一次移除所有的`a`，第二次移除所有的`b`；
3. 用双指针来判断回文串。