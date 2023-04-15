#include<iostream>
using namespace std;
#include "MapStore.cpp"
#include <stack>
stack<int> S;
int indegree[MaxVertexNum];
int print[MaxVertexNum];

bool TopoLogicalSort(ALGraph G)
{
    for(int i = 0; i< G.vexnum; i++)
    {
        if(indegree[i] == 0) S.push(i);
    }
    int count = 0;
    while(!S.empty())
    {
        int i = S.top();
        S.pop();
        print[count++] = i;
        for(auto p = G.vertices[i].first; p; p = p->next)
        {
            int v = p->adjvex;
            if(!(--indegree[v]))
            {
                S.push(v);
            }
        }
    }
    if(count < G.vexnum) return false;
    else return true;
}

ALGraph InitALGraphTopo()
{
    ALGraph G;
    cin>>G.vexnum>>G.arcnum;
    for(int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].first = NULL;
    }
    int j,k,l;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>j>>k>>l;
        ArcNode *p;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = k;
        p->info = l;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p;

        indegree[k]++;
    }
    return G;
}

int main()
{
    ALGraph G = InitALGraphTopo();
    TopoLogicalSort(G);
    for(int i = 0; i < G.vexnum; i++)
    {
        cout<<print[i]<<" ";
    }
}
/*
6 8
0 1 1
1 2 1
2 3 1
4 5 1
3 4 1
2 4 1
1 5 1
0 3 1
*/