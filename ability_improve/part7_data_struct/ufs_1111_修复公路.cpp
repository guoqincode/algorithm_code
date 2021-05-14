#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,maxm=100001;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int father[maxn];
int n,m;

inline int findfather(int x){
    if(x==father[x]) return x;
    else return father[x]=findfather(father[x]);
}

inline void Union(int a,int b){
    int fa=findfather(a),fb=findfather(b);
    father[fa]=fb;
}

struct Edge{
    int from;
    int to;
    int t;
}edge[maxm];

inline void init(){
    for(int i=1;i<=n;i++) father[i]=i;
}

bool cmp(Edge a,Edge b){
    return a.t<b.t;
}

int main(){
    n=read(); m=read();
    init();
    for(int i=1;i<=m;i++){
        edge[i].from=read();
        edge[i].to=read();
        edge[i].t=read();
    }
    sort(edge+1,edge+m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        int fa=findfather(edge[i].from),fb=findfather(edge[i].to);
        if(fa!=fb) cnt++,father[fa]=fb;
        if(cnt==n-1){
            cout<<edge[i].t;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
