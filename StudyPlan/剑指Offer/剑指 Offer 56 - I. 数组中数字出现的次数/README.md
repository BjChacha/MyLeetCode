---
title: 数组中数字出现的次数
no: 剑指 Offer 56 - I
difficulty: Medium
tags: [Bit Manipulation, Array]
url: https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
---

# 剑指 Offer 56 - I. 数组中数字出现的次数

[Leetcode](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/)

### 方法1. 位运算

- 对于“找出数组中只出现一次的一个数字”，那么把所有数字都**异或**一次就能得出；
- 对于“找出数组中只出现两次的两个数字”（`a`和`b`），那么把所有数字都**异或**一次，只能得出两个目标数字的**异或**结果（`c = a ^ b`）；
- 观察结果`c`，其中`ci=1`表示数字`a`和`b`在第`i`位不相同；`ci=0`表示数字`a`和`b`在第`i`位相同；
- 可以利用这个特性，将数组中的数字分成两组。比如一组中数字第`i`位为1，另一组中数字第`i`位为0，这样问题就解决了；
- 技巧：`a & (-a)`为`a`中最低位的1。