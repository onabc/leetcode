## 删除链表的倒数第 N 个结点

### 描述

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

### 示例

![img](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

### 思路

让快指针先跑n回合，然后快指针和慢指针同时跑，当快指针到达终点时，慢指针指向的就是我们要删除的节点了。