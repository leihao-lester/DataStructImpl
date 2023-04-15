#include<iostream>
using namespace std;
#include "MapStore.cpp"
#define MaxVertexNum 100
bool visited[MaxVertexNum];

void DFS(MGraph G, int v)
{
    visit(v);
    visited[v] = true;
    for(int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v,w))
    {
        if(!visited[w])
        {
            DFS(G, w);
        }
    }
}

void DFSTraverse(MGraph G)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    for(int v = 0; v < G.vexnum; v++)
    {
        if(!visited[v])
        {
            DFS(G, v);
        }
    }
}

void DFS(ALGraph G, int v)
{
    visit(v);
    visited[v] = true;
    for(int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
    {
        if(!visited[w])
        {
            DFS(G, w);
        }
    }
}

void DFSTraverse(ALGraph G)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!visited[i])
        {
            DFS(G, i);
        }
    }
}

int main()
{
/*
8 7
0 6
6 7
1 2
2 3
3 4
1 5
3 5
*/
    MGraph G = InitMGraph();
    for(int i = 0; i < G.vexnum; i++)
    {
        for(int j = 0; j < G.vexnum; j++)
        {
            cout<<G.Edge[i][j]<<" ";
        }
        cout<<endl;
    }
    DFSTraverse(G);

    // ALGraph ALG = InitALGraph();
    // for(int i = 0; i < ALG.vexnum; i++)
    // {
    //     cout<<i<<":";
    //     ArcNode *p = ALG.vertices[i].first;
    //     while(p)
    //     {
    //         cout<<p->adjvex<<" ";
    //         p = p->next;
    //     }
    //     cout<<endl;
    // }
    // DFSTraverse(ALG);
}