//子任务A 求入度为0的强连通分量个数
//子任务B max(入度为0的个数，出度为0的个数)
//本质上是tarjan求强连通分量
//54'
#include<bits/stdc++.h>
using namespace std;
const int maxn=102,maxm=1e4+5;  //max(maxm)=100*100
int n,tot=0,head[maxn];
int dfn[maxn],low[maxn],stac[maxn],tim=0,top=0,vis[maxn];
int sd[maxn];
int num_edges=0;
int out[maxn],in[maxn];
int col=0;
struct Edge{
    int from;
    int to;
    int next;
}edge[maxm];

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

inline void addedge(int from,int to){
    edge[++tot].to=to;
    edge[tot].from=from;
    edge[tot].next=head[from];
    head[from]=tot;
}

inline void tarjan(int x){
    low[x]=dfn[x]=++tim;
    stac[++top]=x;
    vis[x]=1;
    for(int i=head[x];i;i=edge[i].next){
        int v=edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }else if(vis[x]){
            low[x]=min(low[x],low[v]);
        }
    }
    if(dfn[x]==low[x]){
        int y;
        while(y=stac[top--]){
            // col++;
            sd[y]=x;  //染色
            vis[y]=0;
            if(x==y) break;
        }
    }
}

// void tarjan(int x)
// {
//     low[x] = dfn[x] = ++tim;
//     stac[++top] = x;
//     vis[x] = 1;
//     for (int i = head[x]; i; i = edge[i].next)
//     {
//         int v = edge[i].to;
//         if (!dfn[v])
//         {
//             tarjan(v);
//             low[x] = min(low[x], low[v]);
//         }
//         else if (vis[v])
//         {
//             low[x] = min(low[x], low[v]);
//         }
//     }
//     if (dfn[x] == low[x])
//     {
//         int y;
//         while (y = stac[top--])
//         {
//             sd[y] = x;
//             vis[y] = 0;
//             if (x == y)
//                 break;
//             // p[x] += p[y];
//         }
//     }
// }

int main(){
    n=read();
    // scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int v;
        v=read();
        // scanf("%d",&v);
        while(v){
            // num_edges++;
            addedge(i,v);
            v=read();
        }
    }
    // for(int i=1;i<=tot;i++){
    //     cout<<edge[i].from<<" "<<edge[i].to<<endl;
    // }
    // for(int i=1;i<=)
    for(int i=1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    // for(int i=1;i<=n;i++)
    //     printf("%d\n",sd[i]);
    // sd[y]=x  y属于连通分量x 测试完毕
    // }
    set<int>st;
    for(int i=1;i<=n;i++) st.insert(sd[i]);
    // for(auto it=st.begin();it!=st.end();it++) cout<<*it<<"  ";
    for(int i=1;i<=tot;i++){
        int x=sd[edge[i].from],y=sd[edge[i].to];
        // cout<<edge[i].from<<"  "<<edge[i].to<<endl;
        // cout<<x<<"  "<<y<<endl;
        if(x!=y){
            // cout<<x<<"  "<<y<<endl;
            // x有0?   addedge中的edge[tot]写成了edge[from]
            out[x]++;
            in[y]++;
        }
    }
    // cout<<in[1]<<endl<<in[3]<<endl<<in[4]<<endl;
    int ansa=0,ansb=0;
    for(auto it=st.begin();it!=st.end();it++){
        if(in[*it]==0) ansa++;
        if(out[*it]==0) ansb++;
    }
    // for(int i=1;i<=col;i++){
    //     if(in[col]==0) ansa++;
    //     if(out[col]==0) ansb++;
    // }
    cout<<ansa<<endl<<max(ansa,ansb);
    return 0;
}

