---
title: 二叉搜索树的后序遍历序列
no: 剑指 Offer 33
difficulty: Medium
tags: [Stack, Tree, Binary Search Tree, Recursion, Binary Tree, Monotonic Stack]
url: https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
---

# 剑指 Offer 33. 二叉搜索树的后序遍历序列

[LeetCode](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

### 方法1. 递归

- 判断后序遍历是否为二叉搜索树：
  - 在区间`[a, b]`中，根节点为`b`。在区间`[a, b - 1]`中找到第一个比`b`大的节点`m`，则区间`[a, m - 1]`为`b`的左子树；区间`[m, b - 1]`为`b`的右子树。
  - 如果`[a, b]`中不能正常分成左右两个子树的区间部分，则该序列不是一个合法的二叉搜索树后序遍历。