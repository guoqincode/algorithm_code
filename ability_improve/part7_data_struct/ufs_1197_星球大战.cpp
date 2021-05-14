//正过来很难求，但是可以反过来求
//先把所有的都摧毁 然后逆序建边
#include<bits/stdc++.h>
using namespace std;
const int maxm=2e5+10;
const int maxn=maxm<<1;
int father[maxn];
int n,m,k;
int broken[maxn],Broken[maxn];
int tot=0,head[maxn];
struct Edge{
    int from;
    int to;
    int next;
}edge[maxm<<1];
int ans[maxn];


inline void addedge(int from,int to){
    edge[++tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline int findfather(int x){
    if(x==father[x]) return x;
    else return father[x]=findfather(father[x]);
}

inline void UnIoN(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    father[fa]=fb;
}

inline void Init(){
    for(int i=0;i<=n;i++) father[i]=i;
}

int main(){
    n=read(); m=read();
    Init();
    for(int i=1;i<=m;i++){
        int u=read()+1; //0~n-1  -->  1~n
        int v=read()+1;
        addedge(u,v);
        addedge(v,u);
    }
    k=read();
    for(int i=1;i<=k;i++){
        broken[i]=read()+1;
        Broken[broken[i]]=1;    //砸坏了
    }
    int total=n-k;  //打击k次后剩下的点(连通块) (把每个点看成一个连通块)
    for(int i=1;i<=2*m;i++){
        if(!Broken[edge[i].from]&&!Broken[edge[i].to]&&findfather(edge[i].from)!=findfather(edge[i].to)){
            //如果两个城市都没被摧毁 并且两个城市还没有联通
            total--;
            UnIoN(edge[i].from,edge[i].to);
        }
    }
    ans[k+1]=total; //最后一次破坏后的个数
    for(int i=k;i>=1;i--){
        total++;    //修复了一个点 先假设他自己自成一个联通分量
        Broken[broken[i]]=0;
        for(int j=head[broken[i]];j;j=edge[j].next){
            if(!Broken[edge[j].to]&&findfather(broken[i])!=findfather(edge[j].to)){
                total--;
                UnIoN(broken[i],edge[j].to);
            }
        }
        ans[i]=total;
    }
    for(int i=1;i<=k+1;i++) printf("%d\n",ans[i]);
    return 0;
}