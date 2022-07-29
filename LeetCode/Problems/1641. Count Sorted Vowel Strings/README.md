---
title: Count Sorted Vowel Strings
no: 1641
difficulty: Medium
tags: [Dynamic Programming]
url: https://leetcode.com/problems/count-sorted-vowel-strings/
---

# 1641. Count Sorted Vowel Strings

[LeetCode](https://leetcode.com/problems/count-sorted-vowel-strings/)

### 方法1. 迭代法

- 从`n=1`开始，计算第`n`次迭代时，以`c={a,e,i,o,u}`结尾的**排列**的个数；
- 进入下一次迭代时（`n=n+1`）,以`c`结尾的排列就看成以`c`开头的排列进行计算；
- 比如第`n`次迭代时，排列`a****e`有`k`个，那么在第`n+1`次迭代时，因为以`e`开头的排列可以派生出`4`个新的排列（`{e,i,o,u}`）。那么该排列共能派生出`k*4`个排列。


### 方法2. 组合数学（带重复元素的k组合数）

- 由于要求是要按照字典序，故每个组合只有一个合法的排列。因此可以转化为求带重复元素的k组合数问题；
- 公式：$\frac{(n + k - 1)!}{n!(k - 1)!}$
- 其中，`n`为组合大小（长度为`n`）；`k`为元素容量（有`k=5`个元音字母）。