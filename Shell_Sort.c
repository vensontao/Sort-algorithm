/*************************************************************************************/
/*         希尔排序算法函数
/*------------------------------------------------------------------------------------
/*  作    者：vensontao
/*  版 本 号：1.0.0
/*  创建时间：2017-01-09
/*------------------------------------------------------------------------------------
/*  希尔排序时间复杂度最好的情况为O(n), 最坏的情况是O(n^2), 是稳定的排序算法
/*  基本思想是: 将一个记录插入到已经排好序的有序表中, 从而得到一个新的,记录数增1的有序表
/************************************************************************************/

#include <stdio.h>

/****************************************************************************/ 
/*希尔排序:先将整个待排元素序列分割成若干子序列（由相隔某个“增量”的元素组成的）分别进行 
直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时， 
再对全体元素进行一次直接插入排序。其时间复杂度为O(n^3/2),要好于直接插入排序的O(n^2) */ 
void  ShellSort( int  arr[],  int  num) 
{ 
     int  i, j, gap, temp; 
     for  (gap = num /  2 ; gap >  0 ; gap /=  2 )  //gap 的取值方法不一 
    { 
         for  (i = gap; i < num; i++) 
        { 
            temp = arr[i]; 
             for  (j = i - gap; j >=  0  && arr[j] > temp; j -= gap) 
                arr[j + gap] = arr[j]; 
            arr[j + gap] = temp; 
        } 
    } 
} 


//==============================================================
//   希尔排序算法
//==============================================================
void Shell_Sort1(int a[], int n)
{
    int i, j, gap;
    for(gap = n/2; gap>0; gap /= 2) // 步长
        for(i = 0; i < gap; ++i)
        {
            for(j = i+gap; j<n;j+=gap)
            {
                if(a[j] < a[j-gap])
                {
                    int temp = a[j];
                    int k = j-gap;
                    while(k>=0 && a[k] > temp)
                    {
                        a[k+gap] = a[k];
                        k -= gap;
                    }
                    a[k+gap] = temp;
                }
            }
        }
}

//==============================================================
//   希尔排序算法
//==============================================================
void Shell_Sort2(int a[], int n)
{
    int i,j,tmp,d;
    for(d=n/2;d>0;d/=2)
    {
        for(i=d;i<n;i++)
        {
            tmp=a[i];
            for(j=i-d;j>=0;j-=d)
            {
                if(tmp<a[j])
                    a[j+d]=a[j];
                else
                    break;
            }
            a[j+d]=tmp;
        }
    }
}

//==============================================================
//   希尔排序算法
//==============================================================
void Shell_Sort3(int arr[], int size)
{
    int i,j,k,temp;
    for(i=size/2;i>0;i/=2)
    {
        for(j=i;j<size;j++)
        {
            temp=arr[j];
            for(k=j-i;k>=0&&temp<arr[k];k-=i)
            {
                arr[k+i]=arr[k];
            }
            arr[k+i]=temp;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
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

    Shell_Sort(array, n);

    PrintArray(array, n);    // 排序后
}