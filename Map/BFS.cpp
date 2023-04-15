#include <iostream>
#include <queue>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#include "MapStore.cpp"

bool visited[MaxVertexNum]; // 访问标记数组
queue<int> Q;

void BFS(MGraph G, int v)
{
    visit(v);
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        v = Q.front(); // 注意这里的v是队头元素
        Q.pop();
        for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFSTraverse(MGraph G)
{
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = false;
    // InitQueue Q;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visited[i])
            BFS(G, i);
    }
}

void BFS(ALGraph G, int v)
{
    visit(v);
    visited[v] = true;
    Q.push(v);
    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        for(int w = FirstNeighbor(G, v); w>=0; w = NextNeighbor(G, v, w))
        {
            if(!visited[w])
            {
                visit(w);
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}

void BFSTraverse(ALGraph G)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        visited[i] = 0;
    }
    for(int i = 0; i < G.vexnum; i++)
    {
        if(!visited[i])
        {
            BFS(G, i);
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
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            cout << G.Edge[i][j] << " ";
        }
        cout << endl;
    }

    BFSTraverse(G);


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
    // BFSTraverse(ALG);
}