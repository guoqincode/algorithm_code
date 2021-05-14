#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 15;
const int inf = 0x3f3f3f3f;
int n, p, r, tot, tim, top, s;
int head[maxn], sd[maxn], dfn[maxn], low[maxn]; //DFN(u)为节点u搜索被搜索到时的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号
int stac[maxn], vis[maxn];    //栈只为了表示此时是否有父子关系
int cost[maxn]; //收买的间谍所需花费
int col=0,cost_col[maxn],size_col[maxn];   //col 代表属于哪个分量 cost_col 表示该连通分量的最小花费
int in[maxn];
int ans=0;
struct EDGE
{
    int to;
    int next;
    int from;
} edge[maxn * 10];
inline void addedge(int x, int y)
{
    edge[++tot].next = head[x];
    edge[tot].from = x;
    edge[tot].to = y;
    head[x] = tot;
}

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

inline void tarjan(int x)
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
        col++;
        // cost_col[col]=cost[x];
        int y;
        while (y = stac[top--])
        {
            sd[y] = col;
            vis[y] = 0;
            size_col[col]++;
            cost_col[col]=min(cost_col[col],cost[y]);
            if (x == y) break;
        }
    }
}
int main(){
    n=read();
    fill(cost+1,cost+n+1,inf);
    fill(cost_col+1,cost_col+n+1,inf-10);
    p=read();
    for(int i=1;i<=p;i++){
        int a,b;
        a=read(); b=read();
        cost[a]=b;
    }
    r=read();
    for(int i=1;i<=r;i++){
        int a,b;
        a=read(); b=read();
        addedge(a,b);   //a->b a间谍掌握b间谍的证据
    }
    for(int i=1;i<=n;i++){
        //如果它能够被贿赂 就以他开始找环
        if(!dfn[i]&&cost[i]!=inf) tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            printf("NO\n%d\n",i);
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=edge[j].next){
            if(sd[i]!=sd[edge[j].to]){
                in[sd[edge[j].to]]++;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=col;i++){
        if(!in[i]) ans+=cost_col[i];
    }
    printf("%d\n",ans);
    return 0;
}