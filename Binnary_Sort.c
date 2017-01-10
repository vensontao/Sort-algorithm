/*************************************************************************************/
/*         折半插入排序算法函数
/*------------------------------------------------------------------------------------
/*  作    者：vensontao
/*  版 本 号：1.0.0
/*  创建时间：2017-01-09
/*------------------------------------------------------------------------------------
/*  插入排序时间复杂度最好的情况为O(n), 最坏的情况是O(n^2), 是稳定的排序算法
/*  基本思想是: 将一个记录插入到已经排好序的有序表中, 从而得到一个新的,记录数增1的有序表
/************************************************************************************/

#include <stdio.h>

//==============================================================
//   折半插入排序算法
//==============================================================
void Binsert_Sort(int a[], int len)
{
    int i, j;
    int low, high, mid;
    int temp;
    for(i = 1; i < len; i++)
    {
        low = 1;
        high = i-1;
        temp = a[i];
        while (low <= high)
        {
            mid = (low+high)/2;
            if(temp < a[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        for(j = i-1; j >=high+1; --j)
        {
            a[j+1] = a[j];
        }
        a[high+1] = temp;
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

//==============================================================
//    主函数入口
//--------------------------------------------------------------
int main()
{
    int i;
    int array[] = {95, 45, 15, 78, 84, 51, 24, 12};
    int n=sizeof(array)/sizeof(int);

    PrintArray(array, n);    // 排序前

    Binsert_Sort(array, n);

    PrintArray(array, n);    // 排序后
}