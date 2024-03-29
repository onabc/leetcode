#### 括号生成

### 描述

数字 `n` 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 **有效的** 括号组合。

### 示例

```
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

输入：n = 1
输出：["()"]
```

### 思路

这个字符串的构建，就是一步一步加括号，n 正好是左括号的最大个数，有左必有右，无左则无右。所以，右括号的最大个数是当前左括号的个数。设为m。

初始状态下，m = 0，因为此刻没有左括号。所以有以下判断。

```cpp
if (n>0) addLeftParenthesis;
if (m>0) addRightParenthesis;
```

`addLeftParenthesis` 和 `addRightParenthesis` 都是加括号这个动作，只不过一个是 + "("，一个是 + ")"
。可以合并，而，我们这个判断，恰好是在抉择该加哪一个括号，也属于加括号这个动作。这里我才反应过来，这原来是一个递归的动作。可以写一个递归的函数表达：

```cpp
void addParenthesis(string str, n, m) {
    if (n>0) addParenthesis(str+"(", n-1, m+1);
    if (m>0) addParenthesis(str+")", n, m-1);
}
```

不能无限递归啊，退出条件是什么呢？当左括号已经达到最大个数，且右括号也达到最大个数，则退出。即 `n==0 && m==0`，加上这个条件即可。


