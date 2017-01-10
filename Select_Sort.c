/*************************************************************************************/
/*         选择排序算法函数
/*------------------------------------------------------------------------------------
/*  作    者：vensontao
/*  版 本 号：1.0.0
/*  创建时间：2017-01-09
/*------------------------------------------------------------------------------------
/*  选择排序时间复杂度最好的情况为O(n), 最坏的情况是O(n^2), 是稳定的排序算法
/*  基本思想是: 将一个记录插入到已经排好序的有序表中, 从而得到一个新的,记录数增1的有序表
/************************************************************************************/

#include <stdio.h>

//====================================================================================
//   选择排序算法
//====================================================================================
void Select_Sort0(int array[], int n)
{  
    int i, j, min;
    int temp;
    for(i = 0; i < n - 1; ++i)
    {  
        min = i;                         // 开始一趟选择排序，假定第i个元素是后面n - i + 1个未排序的元素中最小的元素  
        for(j = i + 1; j < n; ++j)
            if(array[j] < array[min])    // 如果发现比当前最小元素还小的元素，则更新记录最小元素的下标d  
                min = j;

        if(min != i)                     // 如果最小元素的下标不是后面n - i + 1的未排序序列的第一个元素，则需要交换第i个元素和后面找到的最小元素的位置  
        {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

//===================================================================================
//   选择排序算法
//===================================================================================
void Select_Sort1(int a[], int n)
{
    int i,j,min,temp;
    for(i=0; i< n-1; i++)
    {
        min = arr[i];//以此元素为基准
        for(j=i+1; j<n; j++)//从j往前的数据都是排好的，所以从j开始往下找剩下的元素中最小的
        {
            if(min>arr[j])//把剩下元素中最小的那个放到arr[j]中 
            {
                temp = arr[j];
                arr[j] = min;
                min = temp;
            }
        }
    }
}

//===================================================================================
//   选择排序算法
//===================================================================================
void select_sort2(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0; i < len-1; i++)
    {
        for (j =i+1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//===================================================================================
// 打印输出数组元素, 其中n为数组元素个数，0~n-1；
//===================================================================================
void PrintArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

//--------------------------------------------------------------
//    主函数入口
//--------------------------------------------------------------
int main()
{
    int i;
    int array[] = {95, 45, 15, 78, 84, 51, 24, 12};
    int n=sizeof(array)/sizeof(int);

    PrintArray(array, n);    // 排序前

    Select_Sort0(array, n);

    PrintArray(array, n);    // 排序后
}