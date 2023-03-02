#### 搜索旋转排序数组

### 描述

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3
处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

### 示例

```
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

```
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
```

```
输入：nums = [1], target = 0
输出：-1
```

### 思路

以二分搜索为基本思路：

+ `nums[0] <= nums[mid]`（0 - mid不包含旋转）且`nums[0] <= target <= nums[mid]` 时 high 向前规约；

+ `nums[mid] < nums[0]`（0 - mid包含旋转），`target <= nums[mid] < nums[0]` 时向前规约（target 在旋转位置到 mid 之间）

+ `nums[mid] < nums[0]`，`nums[mid] < nums[0] <= target` 时向前规约（target 在 0 到旋转位置之间）

其他情况向后规约，也就是说`nums[mid] < nums[0]`，`nums[0] > target`，`target > nums[mid]` 三项均为真或者只有一项为真时向后规约。
