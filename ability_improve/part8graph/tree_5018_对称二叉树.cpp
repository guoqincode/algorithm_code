//对称二叉树
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int size[maxn],tree[maxn][2],val[maxn];
int n;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

bool check(int u,int v){
    //验证根节点的左子树u和右子树v是否对称
    if(u==-1&&v==-1) return true;   //只有根节点的数肯定对称
    if(u!=-1&&v!=-1&&val[u]==val[v]&&check(tree[u][0],tree[v][1])&&check(tree[u][1],tree[v][0])) return true;
    return false;
    //判断是否是对称的完毕 答案是要计算节点最多的对称二叉树 所以要再加一个计算节点数的函数
}

void dfs(int x){
    // if(size[x]) return size[x];
    size[x]=1;
    if(tree[x][0]!=-1){
        dfs(tree[x][0]);
        size[x]+=size[tree[x][0]];
    }
    if(tree[x][1]!=-1){
        dfs(tree[x][1]);
        size[x]+=size[tree[x][1]];
    }
    // return size[x];
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=1;i<=n;i++){
        tree[i][0]=read(),tree[i][1]=read();
    }
    dfs(1);
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(check(tree[i][0],tree[i][1])) ans=max(ans,size[i]);
    }
    cout<<ans;
    return 0;
}