#include <iostream>
using namespace std;
#include "MapStore.cpp"
#include <queue>

int d[MaxVertexNum];
int path[MaxVertexNum];
int visited[MaxVertexNum];
queue<int> Q;

// 求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(MGraph G, int u)
{
    // d[i]表示从u到i结点的最短路径
    for (int i = 0; i < G.vexnum; i++)
    {
        d[i] = INF;   // 初始化路径长度
        path[i] = -1; // 最短路径从哪个顶点出来
    }
    visited[u] = true;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop(); // 队头元素出队
        for (int w = FirstNeighbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
            if (!visited[w]) // w为u尚未访问的邻接顶点
            {
                visited[w] = true; // 设置已访问标签
                d[w] = d[u] + 1;   // 路径长度加一
                path[w] = u;       // 最短路径应从u到w
                Q.push(w);         // 顶点w入队
            }
        }
    }
}

int main()
{
    MGraph G = InitMGraph();
    /*
6 9
0 1
1 2
1 4
1 3
2 4
2 5
2 3
4 3
3 5
    */
    BFS_MIN_Distance(G, 0);
    for (int i = 0; i < G.vexnum; i++)
    {
        cout << d[i] << " ";
    }
    cout<<endl;
    for (int i = 0; i< G.vexnum; i++)
    {
        cout << path[i] << " ";
    }
}