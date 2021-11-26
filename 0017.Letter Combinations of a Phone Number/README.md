## 电话号码的字母组合

### 描述

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2021/11/09/200px-telephone-keypad2svg.png)

### 示例

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```
输入：digits = "2"
输出：["a","b","c"]
```

```
输入：digits = ""
输出：[]
```

### 思路

假如是 "23" ，那么

第 1 次 for 循环结束后变为 a, b, c；

第 2 次 for 循环的第 1 次 while 循环 a 出队，分别加上 d e f 然后入队，就变成 b c ad ae af

第 2 次 for 循环的第 2 次 while 循环 b 出队，分别加上 d e f 然后入队，就变成 c ad ae af bd be bf

第 2 次 for 循环的第 3 次 while 循环 c 出队，分别加上 d e f 然后入队，就变成 ad ae af bd be bf cd ce cf

这样的话队列的元素长度再也没有等于 1 的了就出了 while 循环。

![img](https://windliang.oss-cn-beijing.aliyuncs.com/17_2.jpg)