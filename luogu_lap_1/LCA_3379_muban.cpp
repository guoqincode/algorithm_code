//lca 倍增方式模板
#include<bits/stdc++.h>
using namespace std;
const int maxn=500050;
int n,m,s;
struct Edge{
    int to;
    int next;
}edge[maxn<<1];
int head[maxn],tot=0;
int lg[maxn];
int depth[maxn],fa[maxn][20];    //fa[i][j]表示节点i的2^j级祖先
inline void addedge(int from,int to){
    //前向星式建图 
    tot++;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

inline void init_lg(){
    //为了跑的快一些，加一个常数优化  预先算出log2(i)+1的值
    for(int i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]==i);
}

inline void dfs(int now,int father){    //now表示当前节点 fath表示它的父亲节点
    fa[now][0]=father;
    depth[now]=depth[father]+1;
    for(int i=1;i<=lg[depth[now]];i++){
        fa[now][i]=fa[fa[now][i-1]][i-1];
        /*算法核心 now的2^i祖先等于now的2^(i-1)祖先的2^(i-1)祖先 2^i=2^(i-1)+2^(i-1)*/
    }
    for(int i=head[now];i;i=edge[i].next){
        if(edge[i].to!=father) dfs(edge[i].to,now);
    }
}

inline int LCA(int x,int y){
    if(depth[x]<depth[y]) swap(x,y);    //保持x的深度>=y
    
    
    while(depth[x]>depth[y]) x=fa[x][lg[depth[x]-depth[y]]-1];
    //if(x向上跳还是比y低) x向上跳

    if(x==y) return x;  //if(x ,y 重合) return x

    for(int k=lg[depth[x]]-1;k>=0;k--){ //不断向上跳
        if(fa[x][k]!=fa[y][k]){     //if(向上跳 y向上跳 未重合) x向上跳 y向上跳
            //因为我们要跳到他们LCA的下面一层，所以他们肯定不相等
            x=fa[x][k],y=fa[y][k];
        }
    }
    return fa[x][0];
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    init_lg();
    dfs(s,0);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
    return 0;
}