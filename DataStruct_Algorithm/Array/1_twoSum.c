/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。


示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <stdio.h>
#include <stdlib.h>

int * twoSum(int * nums, int numsSize, int target, int * returnSize);
// int calculate(int *, int target, int *);


int main()
{
    int nums[4] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;
    int returnSize = 0;
    int * result = NULL;
    result = twoSum(nums, numsSize, target, &returnSize);
    // calculate(nums, targets, result);

    printf("[%d - %d]\n", result[0], result[1]);
    free(result);
    return 0;
}

int * twoSum(int * nums, int numsSize, int target, int * returnSize)
{
    int i, j;
    int * result = NULL;
    for (i = 0; i < numsSize; i++){
        for (j = i + 1; j < numsSize; j++){
            if (target == nums[i] + nums[j]){
                result = (int *)malloc(sizeof(int) * 2);
                if (NULL == result){
                    return NULL;
                }
                result[0] = i, result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

#if 0

//标准答案
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
#endif

























