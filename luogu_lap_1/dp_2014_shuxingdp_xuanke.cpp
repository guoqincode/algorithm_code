//p2014 树形dp 选课
#include<bits/stdc++.h>
using namespace std;
const int maxn=301;
int s[maxn],in[maxn];   //s[i]表示第i门课的分数 in[i]表示第i门课的先修课
int n,m;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int to;
    int next;
}edge[maxn];
int tot=0,head[maxn];
int f[maxn][maxn];
inline void addedge(int from,int to){
    edge[++tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

void dfs(int now){
    for(int i=head[now];i;i=edge[i].next){
        int to=edge[i].to;
        dfs(to);
        for(int j=m+1;j>=1;j--){
            for(int k=0;k<j;k++){
                f[now][j]=max(f[now][j],f[to][k]+f[now][j-k]);
            }
        }
    }
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        //0号节点不用特殊去管
        int from=read();
        f[i][1]=read();
        addedge(from,i);
    }
    dfs(0);
    cout<<f[0][m+1];
    return 0;
}