//p1273 图dp 有线电视网  树上dp问题
//n->节点总数 m->终端节点->叶节点
//根 1 转播站[2,n-m] 叶子节点[n-m+1,n]
//k a1 c1 ...
//目的不是单个不亏本 是整体不亏本
#include<bits/stdc++.h>
using namespace std;
const int maxn=3010,maxm=maxn*maxn; //1e7
int n,m,have[maxn];
const int inf=-0x3f3f3f3f;
int dp[maxn][maxn]; //dp[i][j]表示前i个点选择了j个时的最大值
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct Edge{
    int from;
    int to;
    int next;
    int dis;
}edge[maxm];
int tot=0,head[maxn];
inline void addedge(int from,int to,int dis){
    edge[++tot].from=from;
    edge[tot].to=to;
    edge[tot].dis=dis;
    edge[tot].next=head[from];
    head[from]=tot;
}

inline int dfs(int u){
    if(u>n-m){
        dp[u][1]=have[u];   
        return 1; //返回这个点代表的个数 即为1
    }
    int sum=0,t;
    for(int i=head[u];i;i=edge[i].next){
        int to=edge[i].to;
        t=dfs(to);
        sum+=t;
        for(int j=sum;j>0;j--){
            for(int k=1;k<=t;k++){
                if(j-k>=0) dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[to][k]-edge[i].dis);
            }
        }
    }
    return sum;
}


int main(){
    n=read(); m=read();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) dp[i][j]=inf;
    }
    for(int i=1;i<=n-m;i++){
        int k; k=read();
        int a,c;
        for(int j=1;j<=k;j++){
            a=read(); c=read();
            addedge(i,a,c);
        }
    }
    for(int i=n-m+1;i<=n;i++) have[i]=read();
    for(int i=1;i<=n;i++) dp[i][0]=0;
    dfs(1); //从根节点开始深搜
    for(int i=n;i>=1;i--){
        if(dp[1][i]>=0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}