---
title: 不用加减乘除做加法
no: 剑指 Offer 65
difficulty: Easy
tags: [Bit Manipulation, Math]
url: https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
---

# 剑指 Offer 65. 不用加减乘除做加法

[Leetcode](https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/)

### 方法1. 位运算

- **无进位加法**与**异或**位运算相同；**进位结果**与**与**运算相同（并左移一位）。
- 用位运算来模拟加法可分位两个步骤：
  - 用**异或**位运算得出无进位加法结果：`p1 = a ^ b`；
  - 用与位运算得出进位结果：`p2 = (a & b) << 1`；
  - 两个结果相加就是最终结果：`r = p1 + p2`；
- 因为最后又演变成一个加法问题，那么上述过程就是一个循环内的步骤，直至不产生进位`p2 = 0`为止。