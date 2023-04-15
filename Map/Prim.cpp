#include<iostream>
using namespace std;
#include "MapStore.cpp"
int lowcost[MaxVertexNum];

void prim(MGraph G)
{
    int ans = 0;
    int minval, k;
    for(int i = 0; i < G.vexnum; i++)
    {
        lowcost[i] = G.Edge[i][0];
    }
    for(int i = 1; i < G.vexnum; i++)
    {
        int minval = INF; // 记录当前最小权值
        for(int j = 0; j < G.vexnum; j++)
        {
            if(lowcost[j] > 0 && lowcost[j] < minval)
            {
                k = j;
                minval = lowcost[j];
            }
        }
        if(minval == INF)
        {
            cout<< "false"<<endl;
            return;
        }
        ans += minval;
        lowcost[k] = 0; // 标记该点
        for(int j = 0; j < G.vexnum; j++)
        {
            if(lowcost[j] > 0 && lowcost[j] > G.Edge[k][j])
            {
                lowcost[j] = G.Edge[k][j];
            }
        }
    }
    cout<< ans<<endl;
}

int main()
{
    MGraph G = InitMGraph(1);
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if(G.Edge[i][j] == INF) cout << "INF" << "\t";
            else cout << G.Edge[i][j] << "\t";
        }
        cout << endl;
    }
    prim(G);
    /*
6 10
0 1 2
1 2 3
0 3 1
1 3 4
2 3 3
2 4 2
0 5 5
3 5 2
3 4 7
4 5 6
    */
}