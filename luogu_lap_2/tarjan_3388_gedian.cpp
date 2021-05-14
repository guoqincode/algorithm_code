//割点模板
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5, maxm = 2e5 + 5;
struct Edge
{
    int to;
    int next;
} edge[maxm];

int n, m, head[maxn], tot = 0;
int dfn[maxn], low[maxn], idx = 0, cut[maxn], ans = 0;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void addedge(int from, int to)
{
    tot++;
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot;
}
//对于根节点，判断是不是割点很简单——计算其子树数量，如果有2棵即以上的子树，就是割点。因为如果去掉这个点，这两棵子树就不能互相到达。
//对于非根节点，判断是不是割点就有些麻烦了。我们维护两个数组dfn[]和low[]，dfn[u]表示顶点u第几个被（首次）访问，
//low[u]表示顶点u及其子树中的点，通过非父子边（回边），能够回溯到的最早的点（dfn最小）的dfn值（但不能通过连接u与其父节点的边）。
//对于边(u, v)，如果low[v]>=dfn[u]，此时u就是割点。
//但这里也出现一个问题：怎么计算low[u]。
//假设当前顶点为u，则默认low[u]=dfn[u]，即最早只能回溯到自身。
//有一条边(u, v)，如果v未访问过，继续DFS，DFS完之后，low[u]=min(low[u], low[v])；
//如果v访问过（且u不是v的父亲），就不需要继续DFS了，一定有dfn[v]<dfn[u]，low[u]=min(low[u], dfn[v])。

inline void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++idx;
    int child = 0;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int nx = edge[i].to;
        if (!dfn[nx])
        {
            
            tarjan(nx, fa);

            low[u] = min(low[u], low[nx]);

            if (low[nx] >= dfn[u] && u != fa)
                cut[u] = 1; //

            if (u == fa)
                child++;
        }
        low[u] = min(low[u], dfn[nx]);
    }

    if (child >= 2 && u == fa)
        cut[u] = 1; //根节点的子树>=2 一定是割点
}

int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        x = read();
        y = read();
        addedge(x, y);
        addedge(y, x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
            ans++;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}
