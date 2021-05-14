#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=5e3+10,maxm=2e5+10;
struct Edge{
    int from;
    int to;
    int dis;
}edge[maxm];
int father[maxn];

inline int findfather(int x){
    if(x==father[x]) return x;
    else return father[x]=findfather(father[x]);
}

bool cmp(Edge a,Edge b){
    return a.dis<b.dis;
}

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
int main(){
    n=read(); m=read();
    for(int i=1;i<=m;i++){
        edge[i].from=read();
        edge[i].to=read();
        edge[i].dis=read();
    }
    for(int i=1;i<=n;i++) father[i]=i;
    sort(edge+1,edge+m+1,cmp);
    int ans=0;
    int cnt=0;
    for(int i=1;i<=m;i++){
        int u=edge[i].from,v=edge[i].to;
        if(findfather(u)!=findfather(v)){
            cnt++;
            ans+=edge[i].dis;
            int fa=findfather(u),fb=findfather(v);
            father[fa]=fb;
            if(cnt==n-1){
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<"orz";
    return 0;
}