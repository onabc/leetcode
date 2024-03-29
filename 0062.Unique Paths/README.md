## 不同路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

![img.png](img.png)

 ```
 示例一：
 
输入：m = 3, n = 7
输出：28
 ```

```
示例二：

输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```

## 思路：

该题目中机器人只能向下或者向右走一步，所以该题相对于迷宫问题（即可以四个方向都走）用动态规划就很合适。由于只能向下或向右走，则我们此时该位置可以走的路径为上方位置可走的路径加上左边位置可以走的路径之和。即dp[i][j]
= dp[i - 1][j] + dp[i][j - 1]，了解清楚dp数组的含义之后，可以进行代码实现！

