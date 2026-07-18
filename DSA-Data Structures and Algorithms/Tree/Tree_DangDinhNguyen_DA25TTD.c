#include <stdio.h>
#include <stdlib.h>

typedef struct TNode
{
    int Key;
    struct TNode *pLeft;
    struct TNode *pRight;
} TNode;

typedef TNode* TREE;

TNode* CreateNode(int x)
{
    TNode *p = (TNode*)malloc(sizeof(TNode));

    p->Key = x;
    p->pLeft = NULL;
    p->pRight = NULL;

    return p;
}

int InsertNode(TREE *T, int x)
{
    if(*T == NULL)
    {
        *T = CreateNode(x);
        return 1;
    }

    if(x == (*T)->Key)
        return 0;

    if(x < (*T)->Key)
        return InsertNode(&(*T)->pLeft, x);

    return InsertNode(&(*T)->pRight, x);
}

int CountLeaf(TREE T)
{
    if(T == NULL)
        return 0;

    if(T->pLeft == NULL && T->pRight == NULL)
        return 1;

    return CountLeaf(T->pLeft)
         + CountLeaf(T->pRight);
}

int CountOneChild(TREE T)
{
    int dem = 0;

    if(T == NULL)
        return 0;

    if((T->pLeft == NULL && T->pRight != NULL) ||
       (T->pLeft != NULL && T->pRight == NULL))
        dem = 1;

    return dem
         + CountOneChild(T->pLeft)
         + CountOneChild(T->pRight);
}

int CountTwoChild(TREE T)
{
    int dem = 0;

    if(T == NULL)
        return 0;

    if(T->pLeft != NULL && T->pRight != NULL)
        dem = 1;

    return dem
         + CountTwoChild(T->pLeft)
         + CountTwoChild(T->pRight);
}

int CountLessThanX(TREE T, int x)
{
    if(T == NULL)
        return 0;

    if(T->Key < x)
        return 1
             + CountLessThanX(T->pLeft, x)
             + CountLessThanX(T->pRight, x);

    return CountLessThanX(T->pLeft, x);
}

int CountGreaterThanX(TREE T, int x)
{
    if(T == NULL)
        return 0;

    if(T->Key > x)
        return 1
             + CountGreaterThanX(T->pLeft, x)
             + CountGreaterThanX(T->pRight, x);

    return CountGreaterThanX(T->pRight, x);
}

int CountInRange(TREE T, int x, int y)
{
    if(T == NULL)
        return 0;

    if(T->Key > x && T->Key < y)
        return 1
             + CountInRange(T->pLeft, x, y)
             + CountInRange(T->pRight, x, y);

    if(T->Key <= x)
        return CountInRange(T->pRight, x, y);

    return CountInRange(T->pLeft, x, y);
}

int Max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int Height(TREE T)
{
    if(T == NULL)
        return 0;

    return Max(Height(T->pLeft),
               Height(T->pRight)) + 1;
}

TNode* SearchAndPrint(TREE T, int k)
{
    while(T != NULL)
    {
        printf("%d ", T->Key);

        if(T->Key == k)
        {
            printf("\n");
            return T;
        }

        if(k < T->Key)
            T = T->pLeft;
        else
            T = T->pRight;
    }

    printf("\n");
    return NULL;
}

int main()
{
    TREE T = NULL;
    //test case sẵn
    int a[] = {50,30,70,20,40,60,80,10,25};
    int n = sizeof(a)/sizeof(a[0]);
    int i;

    for(i = 0; i < n; i++)
        InsertNode(&T, a[i]);

    printf("%d\n", CountLeaf(T));
    printf("%d\n", CountOneChild(T));
    printf("%d\n", CountTwoChild(T));
    printf("%d\n", CountLessThanX(T, 50));
    printf("%d\n", CountGreaterThanX(T, 50));
    printf("%d\n", CountInRange(T, 25, 70));
    printf("%d\n", Height(T));

    SearchAndPrint(T, 60);

    return 0;
}