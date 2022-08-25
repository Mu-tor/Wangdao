#include<bits/stdc++.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

void deletX(LinkList &l, int x)
{
    if (!l)
        return; //空结点
    LNode *p;
    if (l->data == x)
    {
        p = l;
        l = l->next;
        free(p); //删除节点
        deletX(l, x);
    }
    else
        deletX(l->next, x); //检查下一结点
}
void printList(LinkList l)
{
    LNode *p = l;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
LinkList initList(int n)
{
    LinkList l = (LNode *)malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;
    LNode *q = l;
    for (int i = 0; i < n; i++)
    {
        LNode *p;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = i;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return l;
}
int main()
{
    LinkList l = initList(10);
    printList(l);
    deletX(l,0);
    printList(l);
    return 0;
}