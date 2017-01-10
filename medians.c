//========================================================================
//     求中位数
//------------------------------------------------------------------------
//
//========================================================================

#include <stdio.h>

#define N 100

void Bubble_sort(int *list, int len)    // 冒泡排序
{
    int i,j;
    int temp;
    for(i=0;i<len - 1;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(list[j+1]<list[j])
            {
                temp=list[j+1];
                list[j+1]=list[j];
                list[j]=temp;
            }
        }
    }
}


int main()
{
    int i, num;
    int tar[N];
    scanf("%d", &num);
    while(num != 0)
    {
        for(i = 0; i< num; i++)
        {
            scanf("%d", &tar[i]);
        }

        Bubble_sort(tar, num);

        if(num % 2 == 0)
        {
            printf("%lg\n",(tar[num/2] + tar[num/2 - 1]) / 2.0); 
        }
        else
        {
            printf("%lg\n", tar[num/2]*1.0);
        }
        scanf("%d", &num);
    }
    return 0;
}