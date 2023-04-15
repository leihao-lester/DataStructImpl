#include<iostream>
using namespace std;
#define SIZE 10
int DSet[SIZE];

void Initial(int S[])
{
    for(int i = 0; i < SIZE; i++)
    {
        S[i] = -1;
    }
}

int Find(int S[], int x)
{
    while(S[x] >= 0)
    {
        x=S[x];
    }
    return x;
}

// 路径压缩 ？？？
int FindPro1(int S[], int x)
{
    return (S[x]>=0)?FindPro1(S, S[x]):x;
}

int FindPro2(int S[], int x)
{
    int root = x;
    while (S[root] >= 0) // 循环找到根
    {
        root = S[root];
    }
    while (x != root) // 压缩路径
    {
        int t = S[x]; // t指向x的父节点
        S[x] = root; // x直接挂到根节点
        x = t;
    }
    return root;
}

void Union(int S[], int Root1, int Root2)
{
    // 要求Root1与Root2是不同的集合
    if(Root1 == Root2) return;
    S[Root2] = Root1;
}

// 小树合并到大树
void UnionPro(int S[], int Root1, int Root2)
{
    if(Root1 == Root2) return;
    if(S[Root2] > S[Root1]) // Root2的结点数更少
    {
        S[Root1] += S[Root2]; // 累加结点数，用-1表示一个结点，-3表示三个结点
        S[Root2] = Root1; // 小树合并到大树
    } else{
        S[Root2] += S[Root1]; 
        S[Root1] = Root2;
    }
}

int main()
{
    Initial(DSet);
    Union(DSet, 1, 2);
    Union(DSet, 1, 6);
    Union(DSet, 1, 8);
    Union(DSet, 3, 9);
    for(int i=0; i < SIZE; i++)
        cout<<DSet[i]<<" ";
    cout<<endl<<Find(DSet, 8);
}