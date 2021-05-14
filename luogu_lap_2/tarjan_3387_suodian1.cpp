#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 15;
int n, m, sum, tim, top, s;
int p[maxn], head[maxn], sd[maxn], dfn[maxn], low[maxn]; //DFN(u)为节点u搜索被搜索到时的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号
int stac[maxn], vis[maxn];                               //栈只为了表示此时是否有父子关系
int h[maxn], in[maxn], dist[maxn];
struct EDGE
{
    int to;
    int next;
    int from;
} edge[maxn * 10], ed[maxn * 10];
void add(int x, int y)
{
    edge[++sum].next = head[x];
    edge[sum].from = x;
    edge[sum].to = y;
    head[x] = sum;
}
void tarjan(int x)
{
    low[x] = dfn[x] = ++tim;
    stac[++top] = x;
    vis[x] = 1;
    for (int i = head[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if (vis[v])
        {
            low[x] = min(low[x], low[v]);
        }
    }
    if (dfn[x] == low[x])
    {
        int y;
        while (y = stac[top--])
        {
            sd[y] = x;
            vis[y] = 0;
            if (x == y)
                break;
            p[x] += p[y];
        }
    }
}
int topo()
{
    queue<int> q;
    // int tot = 0;
    for (int i = 1; i <= n; i++)
        if (sd[i] == i && !in[i])
        {
            q.push(i);
            dist[i] = p[i];
        }
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (int i = h[k]; i; i = ed[i].next)
        {
            int v = ed[i].to;
            dist[v] = max(dist[v], dist[k] + p[v]);
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }
    int ans = 0;
    // for (int i = 1; i <= n; i++)
        // printf("topo:%d  : %d      \n", i, dist[i]);

    for (int i = 1; i <= n; i++)

        ans = max(ans, dist[i]);
    return ans;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        int x = sd[edge[i].from], y = sd[edge[i].to];
        if (x != y)
        {
            ed[++s].next = h[x];
            ed[s].to = y;
            ed[s].from = x;
            h[x] = s;
            in[y]++;
        }
    }
    // for (int i = 1; i <= n; i++)
        // printf("p%d  :  %d\n", i, p[i]);

    printf("%d", topo());
    return 0;
}