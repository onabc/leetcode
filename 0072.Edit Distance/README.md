## 编辑距离

给你两个单词word1 和word2， 请返回将word1转换成word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

+ 插入一个字符
+ 删除一个字符
+ 替换一个字符

### 示例一

```
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

### 示例二

```
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
```

## 思路

在确定递推公式的时候，首先要考虑清楚编辑的几种操作，整理如下:

```
if (word1[i - 1] == word2[j - 1])
不操作
if (word1[i - 1] != word2[j - 1])
增 / 删 / 换
```

### 确定dp数组以及下标的含义：

dp[i][j]：dp[i][j] 表示以下标 i−1 为结尾的字符串word1 ，和以下标 j−1 为结尾的字符串word2 ，最近编辑距离为 dp[i][j]。

### 确定递推公式：

如果s[i−1]==t[j−1] ， 有dp[i][j]=dp[i−1][j−1]
如果s[i−1]!=t[j−1]， 有 dp[i][j]=min(dp[i−1][j−1]+1,dp[i−1][j]+1,dp[i][j−1]+1)

### 初始状态：

如果j=0 即以i−1 为结尾的word1，删除i次 dp[i][0]=i
如果i=0 即以j−1 为结尾的word2，删除j 次dp[i][0]=j

### 返回值

dp[i][j] 的最小值