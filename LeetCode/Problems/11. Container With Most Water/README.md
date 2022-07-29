---
title: Container With Most Water
no: 11
difficulty: Medium
tags: [Array, Two Pointers, Greedy]
url: https://leetcode.com/problems/container-with-most-water/
---

# 11. Container With Most Water

[LeetCode](https://leetcode.com/problems/container-with-most-water/)

## 方法1. 双指针+贪心算法

### 思路

- 使用左、右双指针，从两边向中间靠拢，过程中使用贪心策略更新最大容量；
- 移动策略：
  - 双指针的移动策略可以看作对“保留哪个端点”或“抛弃哪个端点”问题的解答。
  - 由于储水容量是由两个端点的**高度较低者决定**，换句话说，较高端点受较低端点约束。故先抛弃**高度较低者**，因为有可能内部存在更高的端点使得容量比目前高；
  - 若左右端点高度一致，则二者均可抛弃。因为内部不可能存在使得容量比目前容量更大的端点。

### 流程

1. 初始化双指针在数组两端；
2. 计算以双指针为边界时的容量，并更新最大容量；
3. **所在高度较小**的指针先动。若高度相等，则双指针一起动（也可以随便动一个，不影响结果）；
4. 重复步骤2，3，直至双指针相遇。