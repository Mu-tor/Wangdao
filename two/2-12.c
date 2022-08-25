#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findMainElem(int A[], int n)
{
    int *p;
    int max = -1, num = 0;
    p = (int *)malloc(sizeof(int)*n);
    memset(p,0,sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        p[A[i]]++;//将p数组中与A对应元素加一
        if (p[A[i]]>max)
        {
            max = p[A[i]];
            num = A[i];
        }
    }
    return max>(n/2)?num:-1;
}
int main()
{
    int A[]={0,2,3,4,1,1,1,1,1,1};
    printf("%d",findMainElem(A,10));
    return 0;
}