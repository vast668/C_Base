#include <stdio.h>

int maxArea(int * height, int heightSize);
int main()
{
    int max_value = 0;
    int num[] = {3, 1, 8, 9, 18};
    
    max_value = maxArea(num, 5); 
    printf("max area is %d\n", max_value);
    return 0;
}

int maxArea(int * height, int heightSize)
{
    int head = 0;
    int rear = heightSize - 1;
    int tempArea = 0;
    int maxArea = 0;

    while (head < rear){
        tempArea = (rear - head) * (height[head] > height[rear] ? 
                    height[rear] : height[head]);
        maxArea = maxArea >= tempArea ? maxArea : tempArea;

        if (height[head] >= height[rear]){
            --rear;
        } else {
            ++head;
        }
    }

    return maxArea;
}