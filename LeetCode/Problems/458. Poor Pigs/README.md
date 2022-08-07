---
title: Poor Pigs
no: 458
difficulty: Hard
tags: [Math, Dynamic Programming, Combinatorics]
url: https://leetcode.com/problems/poor-pigs/
---

# 458. Poor Pigs

[LeetCode](https://leetcode.com/problems/poor-pigs/)

### Solution 1. Math

- 假设只有一只小猪，那么k次试验次数（`minutesToTest / minutesToDie < k + 1`），可以检测`k+1`桶水：小猪每天喝一桶，若第`k`次死掉就是第`k`桶水有毒；若最后没死就是第`k+1`桶水有毒；
- 再假设有两只小猪，那么k次试验次数可以检测`(k+1)^2`桶水：把水桶排列成`(k+1)x(k+1)`桶水，第一只猪按行每次按*行*检测`k+1`桶水，第二只猪每次按*列*检测`k+1`桶水；
- 以此类推，有`n`只小猪，k次试验次数，则可检测`(k+1)^n`桶水。反过来推算，有`m`桶水，需要`log(k+1)/log(2)`只小猪。
