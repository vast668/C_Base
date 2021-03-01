#include <stdio.h>

int maxArea(int * nums, int size_num);
int main()
{
    int max = 0;
    int num[] = {3, 1, 8, 9, 18};
    
    max = maxArea(num, 5); 
    printf("max area is %d\n", max);
    return 0;
}

int maxArea(int * nums, int size_num)
{
    int head = 0;
    int rear = size_num - 1;
    int temp_area = 0;
    int max_area = 0;

    while (rear > head){
        temp_area = (rear - head) * (nums[head] > nums[rear] ? 
                    nums[rear] : nums[head]);
        max_area = max_area >= temp_area ? max_area : temp_area;

        if (nums[head] > nums[rear]){
            --rear;
        } else {
            ++head;
        }
    }

    return max_area;


    return 0;
}