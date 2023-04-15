#include<bits/stdc++.h>
using namespace std;
#define max_N 100
#define max_e 100
int par[max_N];//父亲
int rank1[max_N];//树的高度

struct edge
{
    int u,v,cost;
};
edge es[max_e];
int V,E;//顶点数和边数

bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}

//初始化n个元素
void init_union_find(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rank1[i]=0;
    }
}

int find(int x) //查询树的根
{
    return x==par[x]?x:par[x]=find(par[x]);//使用路径压缩
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)return ;
    if(rank1[x]<rank1[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(rank1[x]=rank1[y]) rank1[x++];
    }
}

bool same(int x,int y)//判断x和y是否属于同一个集合
{
    return find(x)==find(y);
}

int kruskal()
{
    sort(es,es+E,cmp);//按照edge.cost的顺序从小到大排列
    init_union_find(V);//并查集的初始化
    int res=0;
    for(int i=0;i<E;i++)
    {
        edge e=es[i];
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

int main()
{
    cin>>V>>E;
    for(int i=1;i<=E;i++)
    {
        cin>>es[i].u>>es[i].v>>es[i].cost;
    }
    cout<<kruskal();
}