//p1967 火车运输
//kruskal 求最 大 生成树

// 0' 联通的点会输出0 未找到bug

#include<bits/stdc++.h>
using namespace std;
const int maxn=10010,maxm=50050;
int father[maxn];
int n,m,cnt_edges=0,q;
int head[maxn];
int fa[maxn][21],w[maxn][21];
bool vis[maxn];
int deep[maxn];
const int inf=0x3f3f3f3f;
struct Edge{
    int u;
    int v;
    int w;
}edge[maxm];
struct Edge2{
    int to;
    int w;
    int next;
}edge2[maxm];
int tot=0;
inline void addedge(int from,int to,int w){
    tot++;
    edge2[tot].next=head[from];
    edge2[tot].to=to;
    edge[tot].w=w;
    head[from]=tot;
    return;
}

bool cmp(Edge a,Edge b){
    return a.w>b.w;     //大的在前面
}

inline void initfather(){
    for(int i=1;i<=n;i++) father[i]=i;
}
inline int findfather(int x){
    if(father[x]==x) return x;
    else return findfather(father[x]);
}

inline void kruskal(){
    initfather();
    sort(edge+1,edge+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fa=findfather(edge[i].u),fb=findfather(edge[i].v);
        if(fa!=fb){
            father[fb]=fa;
            addedge(edge[i].u,edge[i].v,edge[i].w);
            addedge(edge[i].v,edge[i].u,edge[i].w);
        }
    }
    return;
}

inline void dfs(int node){
    vis[node]=true;
    for(int i=head[node];i;i=edge2[i].next){
        int to=edge2[i].to;
        if(vis[to]) continue;
        deep[to]=deep[node]+1;
        fa[to][0]=node;   //储存父节点
        w[to][0]=edge2[i].w;    //储存到父节点的权值
        dfs(to);
    }
    return ;
}

int lca(int x,int y){
    if(findfather(x)!=findfather(y)) return -1;
    int ans=inf;
    if(deep[x]>deep[y]) swap(x,y);
     //将y节点上提到于x节点相同深度 
    for(int i=20; i>=0; i--)
        if(deep[fa[y][i]]>=deep[x]){
            ans=min(ans, w[y][i]);  //更新最大载重（最小边权） 
            y=fa[y][i]; //修改y位置 
        }
    if(x==y) return ans; //如果位置已经相等，直接返回答案 
    //寻找公共祖先 
    for(int i=20; i>=0; i--){
        if(fa[x][i]!=fa[y][i]){
            ans=min(ans, min(w[x][i], w[y][i])); //更新最大载重（最小边权）
            x=fa[x][i]; 
            y=fa[y][i]; //修改x,y位置 
        }
    }
    ans=min(ans, min(w[x][0], w[y][0]));
    //更新此时x,y到公共祖先最大载重，fa[x][0], fa[y][0]即为公共祖先 
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edge[i].u=a;
        edge[i].v=b;
        edge[i].w=c;
    }
    kruskal();
    for(int i=1;i<=n;i++){
        if(!vis[i]){    //dfs
            deep[i]=1;
            dfs(i);
            fa[i][0]=i;
            w[i][0]=inf;
        }
    }
    for(int i=1; i<=20; i++){   //lca初始化
        for(int j=1; j<=n; j++){
            fa[j][i]=fa[fa[j][i-1]][i-1]; 
            w[j][i]=min(w[j][i-1], w[fa[j][i-1]][i-1]);
        }
    }
    scanf("%d",&q);
    int x,y;
    for(int i=1; i<=q; i++){
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y)); //回答询问 
    }
    return 0;
}