#include <iostream>
using namespace std;
#define MaxVertexNum 100 // 图中顶点数目的最大值
#define INF 0x4f4f4f4f

// 邻接矩阵存储图
typedef struct 
{
    char Vex[MaxVertexNum];               // 顶点表
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵，边表
    int vexnum, arcnum;                   // 图的当前顶点数和弧数
} MGraph;


// 邻接表存储图
typedef struct ArcNode // 边表结点
{
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *next; // 指向下一条弧的指针
    int info;  // 网的边权值
} ArcNode;

typedef struct VNode // 顶点表结点
{
    int data; // 顶点信息
    ArcNode *first; // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices; // 邻接表
    int vexnum, arcnum; // 图的顶点数和弧数
} ALGraph; // ALGraph是以邻接表存储的图的类型


// 十字链表法存储有向图
typedef struct OLArcNode
{
    int tailvex,headvex;
    struct OLArcNode *hlink, *tlink;
    int info;
} OLArcNode;

typedef struct OLVNode
{
    char data;
    OLArcNode *firstin, *firstout;
} OLVNode;

typedef struct OLGraph
{
    OLVNode OLVNodeList[MaxVertexNum];
    int vexnum, arcnum;
}OLGraph;

// 邻接多重表存储无向图
typedef struct AMLArcNode
{
    int mark; // 标志域
    int ivex, jvex; // 边两边顶点在数组中的位置下标
    struct AMLArcNode *ilink, *jlink; // 分别指向与ivex、jvex相关的下一个边
    int info;
} AMLArcNode;

typedef struct AMLVNode
{
    char data;
    AMLArcNode *firstedge;
} AMLVNode;

typedef struct 
{
    AMLVNode AMLVNodeList[MaxVertexNum];
    int vexnum, arcnum;
} AMLGraph;

// 求图G中顶点x的第一个邻接点，返回邻接点号
int FirstNeighbor(MGraph G, int x)
{
    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.Edge[x][i] != 0) return i;
    }
    return -1;
}

int FirstNeighbor(ALGraph G, int x)
{
    if(G.vertices[x].first != NULL) return G.vertices[x].first->adjvex;
    else return -1;
}

// 求图G中顶点x的在y这个邻接点下一个邻接点(假设y是x的一个邻接点)
int NextNeighbor(MGraph G, int x, int y)
{
    if(y == G.vexnum) return -1;
    for(int i = y + 1; i< G.vexnum; i++)
    {
        if(G.Edge[x][i] != 0) return i;
    }
    return -1;
}

int NextNeighbor(ALGraph G, int x, int y)
{
    ArcNode *p = G.vertices[x].first;
    while(p)
    {
        if(p->adjvex == y)
        {
            if(p->next) return p->next->adjvex;
            else return -1;
        }
        p = p->next;
    }
    return -1;
}

void visit(int v)
{
    cout<<v<<endl;
}


MGraph InitMGraph(int mode=0)// mode = 0表示无向无权图；mode = 1 表示无向带权图；mode = 2表示有向无权图；mode = 3表示有向带权图
{
    MGraph G;
    cout<<"input vexnum and arcnum"<<endl;
    cin>>G.vexnum>>G.arcnum;
    if(mode==0)
    {
        for(int s = 0; s < G.vexnum; s++)
            for(int k = 0; k < G.vexnum; k++)
                G.Edge[s][k] = 0;
        cout<<"input edge ,eg:2 3, means<2,3>"<<endl;
        int j,k;
        for(int i = 0; i < G.arcnum; i++)
        {
            cin>>j>>k;
            G.Edge[k][j] = 1;
            G.Edge[j][k] = 1;
        }
    }
    else if(mode == 1)
    {
        for(int s = 0; s < G.vexnum; s++)
        {
            for(int k = 0; k < G.vexnum; k++)
            {
                // G.Edge[s][k] = 0;
                if(s == k)G.Edge[s][k] = 0;
                else G.Edge[s][k] = INF;
            }            
        }

        cout<<"input edge ,eg:2 3 4, means<2,3>=4"<<endl;
        int j,k,l;
        for(int i = 0; i < G.arcnum; i++)
        {
            cin>>j>>k>>l;
            G.Edge[k][j] = l;
            G.Edge[j][k] = l;
        }
    }

    return G;
}


ALGraph InitALGraph()
{
    ALGraph G;
    cout<<"input vexnum and arcnum"<<endl;
    cin>>G.vexnum>>G.arcnum;
    for(int i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].first = NULL;
    }
    cout<<"input edge ,eg:2 3, means<2,3>"<<endl;
    int j,k;
    for(int i = 0; i < G.arcnum; i++)
    {
        cin>>j>>k;
        ArcNode *p;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = k;
        p->next = G.vertices[j].first;
        G.vertices[j].first = p;

        ArcNode *q;
        q = (ArcNode*) malloc(sizeof(ArcNode));
        q->adjvex = j;
        q->next = G.vertices[k].first;
        G.vertices[k].first = q;
    }
    return G;
}