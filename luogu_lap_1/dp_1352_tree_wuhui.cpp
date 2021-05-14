//p1352 没有上司的舞会
//树上dp
#include<bits/stdc++.h>
using namespace std;
const int maxn=6000+5;
vector<int>son[maxn];  //邻接表存储
int n,happy[maxn],root;
int isnotroot[maxn];
int dp[maxn][2];    
//dp[i][0]表示 i点不去参加舞会的最大值
//dp[i][1]表示 i点去参加舞会的最大值
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void dfs(int x){
    dp[x][0]=0;
    dp[x][1]=happy[x];
    for(int i=0;i<son[x].size();i++){
        int v=son[x][i];
        dfs(v);
        dp[x][0]+=max(dp[v][0],dp[v][1]);
        dp[x][1]+=dp[v][0];
    }
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) happy[i]=read();
    for(int i=1;i<=n-1;i++){
        int x,y;
        x=read(); y=read();
        son[y].push_back(x);
        isnotroot[x]=1;
    }
    for(int i=1;i<=n;i++){
        if(isnotroot[i]==0){
            root=i;
            break;
        }
    }
    dfs(root);
    printf("%d",max(dp[root][0],dp[root][1]));
    return 0;
}