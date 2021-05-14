//p5022 dfs 旅行
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
const int maxm=1e4+5;   //双向边
struct Edge{
    int from;
    int to;
    int next;
}edge[maxm];
int n,m;
int tot=0,head[maxn];

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){ x=x*10+(ch-'0'); ch=getchar(); }
    return x*f;
}

inline void addedge(int from,int to){
    edge[++tot].from=from;
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;
}

int main(){
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        int a,b;
        a=read(); b=read();
        addedge(a,b);
        addedge(b,a);
    }

}