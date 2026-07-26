#include <stdio.h>
#include <stdlib.h>

//Size of Array
#define Len 10

//Bubble Sort Function
void Bubble_sort(int arr[], int n)
{
    while(n!=1)
    {
        int Swap = 0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp;
                temp = arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                Swap = 1;
            }
        }
        if(Swap==0) break;
        n--;
    }
}

int main() 
{
    //Example Array
    int Array[Len] = {9,8,5,4,7,6,1,2,0,3};
    
    //Passing Array to Function
    Bubble_sort(Array,Len);
    
    //Print Sorted Array
    for(int i=0;i<Len;i++)
    {
        printf("%d\t", Array[i]);
    }

    return 0;
}