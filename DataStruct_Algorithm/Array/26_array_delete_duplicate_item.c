/*
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main()
{
    int len = 0, i;
    int nums[] = {1, 4, 1, 2, 2};
    
    len = removeDuplicates(nums, 5);
    
    for (i = 0; i < len; i++) {
        printf("[%d]", nums[i]);
    }
    printf("\n");
    
    return 0;
}

int removeDuplicates(int* nums, int numsSize){
    int low = 0, high;

    if (numsSize == 0)
        return 0;
    for (high = 1; high < numsSize; high++) {
        if (nums[high] != nums[low])
            nums[++low] = nums[high];
    }

    return low + 1;
}

/*
分析：

(1)注意是给定排序数组
(2)使用快慢指针
(3)用 high 去找有没有和 low 相同的元素；
(4)如果有的话，那么需要将 high 右移；
(5)如果没有的话，那么需要将 high 所指元素赋值给 low + 1 所指元素；
(6)只有这样才能将之前重复的元素给覆盖；
(7)最后返回 low + 1 即可，其表示非重复元素的个数。

始终保证[low, high]中的数据是不重复的
*/




















