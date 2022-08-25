#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findMinInt(int A[],int n){
    int *B,i = 0;
    B = (int *)malloc(sizeof(int)*n);
    memset(B,0,sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        if (A[i]>0&&A[i]<=n)
        {
            B[A[i]-1] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if(B[i]==0)
            break;
    }
    return i+1;
}
int main(){
    int A[]={-4,3,2,3};
    printf("%d",findMinInt(A,sizeof(A)/sizeof(A[0])));
    return 0;
}