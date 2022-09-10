---
title: Transform to Chessboard
no: 782
difficulty: Hard
tags: [Bit Manipulation, Array, Math, Matrix]
url: https://leetcode.cn/problems/transform-to-chessboard/
---

# 782. Transform to Chessboard

[LeetCode](https://leetcode.cn/problems/transform-to-chessboard/)

## Solution 1. 找规律

- 本题可以总结为两个问题：
  1. 判断`board`能否转换成标准棋盘；
  2. 计算`board`转换成标准棋盘的最少操作；
- 解决问题之前，先共识以下规律：
  - 行的操作，不会影响各列元素的列位置。反之亦然；
  - 基于以上，能够转换成标准棋盘的`board`，必然只存在两种行（或列），而且每种行（列）的数量只差不大于1（考虑奇数棋盘）；
- 对于问题1，计算`board`，是否只存在两种互补的行（或列），而且数量只差不大于1；
  - 可以反过来想，标准棋盘通过简单的列（行）交换操作，无法产生第三种行（列）；
- 对于问题2：计算第一行（列）与两种标准行（列）的距离：即不相等的元素个数；
  - 标准行（列）是指`0101...`或者`1010...`
  - 因为要转换成标准棋盘，每行必然都会成为标准行（列），且`board`里只含有两种互补的行（列），因此当一行（列）转换标准行（列），其他行（列）也必然转换成了标准行（列）；
