#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool minNum(int a, int b, int c)
{
    if (a > b)
        return false;
    else
        return a < c;
}
int findMinD(int A[], int n, int B[], int m, int C[], int p)
{
    int D, mD = __INT_MAX__, i, j, k;
    i = j = k = 0;
    while (i < n && j < m && k < p && mD > 0)
    {
        D = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
        mD = mD > D ? D : mD;
        //printf("%d %d %d\n",A[i], B[j], C[k]);
        if (minNum(A[i], B[j], C[k]))
            i++;
        else if (minNum(B[j], A[i], C[k]))
            j++;
        else
            k++;
    }
    return mD;
}
int main()
{
    int A[] = {-1,0,9};
    int n = sizeof(A)/sizeof(A[0]);
    int B[] = {-25,-10,10,11};
    int m = sizeof(B)/sizeof(B[0]);
    int C[] = {2,9,17,30,41};
    int p = sizeof(C)/sizeof(C[0]);
    printf("%d", findMinD(A,n,B,m,C,p));
    return 0;
}