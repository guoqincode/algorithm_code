#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=301;
int n,m;
const int maxm=100010;

struct Edge{
    int from,to,c;
}edge[maxm];

bool cmp(Edge a,Edge b){
    return a.c<b.c;
}

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch-'0'); ch=getchar();}
    return x*f;
}

int father[maxn];

inline void InIt(){
    for(int i=1;i<=n;i++) father[i]=i;
}

inline int find_father(int x){
    if(x==father[x]) return x;
    else return father[x] = find_father(father[x]);
}

int main(){
    n=read(); m=read();
    InIt();
    // int u,v,c;
    for(int i=1;i<=m;i++){
        edge[i].from=read(); 
        edge[i].to=read();
        edge[i].c=read();
    }
    sort(edge+1,edge+m+1,cmp);
    int ans=0;
    for(int i=1;i<=m;i++){
        int fa=find_father(edge[i].from),fb=find_father(edge[i].to);
        if(fa!=fb){
            ans++;
            father[fa]=fb;
            if(ans==n-1){
                cout<<ans<<" "<<edge[i].c;
                break;
            }
        }
    }
    return 0;
}
