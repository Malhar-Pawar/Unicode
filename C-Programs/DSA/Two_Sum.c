#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    //Allocate memory for two integers
    int *Result = (int*)malloc(2*sizeof(int));
    *returnSize = 2;

    //Code Logic
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                Result[0]=i;
                Result[1]=j;
                return Result;
            }
        }
    }
    *returnSize = 0;
    free(Result);
    return NULL;
}

int main()
{
    int nums[]={2,7,11,15};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int returnSize = 0;

    //Calling the Function
    int* result = twoSum(nums,numsSize, target, &returnSize);

    //Print the Results
    if(result != NULL && returnSize==2)
    {
        printf("Result Indices: [%d, %d]\n", result[0], result[1]);
        printf("Values Check: %d + %d = %d\n", nums[result[0]], nums[result[1]], target);
    }
    else
    {
        printf("No Solutions Found\n");
    }

    //Free Memory
    free(result);
    return 0;
}