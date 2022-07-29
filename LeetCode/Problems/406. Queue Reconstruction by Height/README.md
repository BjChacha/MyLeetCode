---
title: Queue Reconstruction by Height
no: 406
difficulty: Medium
tags: [Array, Greedy, Binary Indexed Tree, Segment Tree, Sorting]
url: https://leetcode.com/problems/queue-reconstruction-by-height/
---

# 406. Queue Reconstruction by Height

[LeetCode](https://leetcode.com/problems/queue-reconstruction-by-height/)

### 方法1 排序

1. 把`people`按照“优先高度降序、其次序号升序”的排序规则进行排序，时间复杂度为O(nlongn)；
2. 遍历`people`，将其中每个`p`插入到新数组中第`p[1]`个位置（因为前面插入的元素都大于等于该元素）。