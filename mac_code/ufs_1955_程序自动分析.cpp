#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
// n<=1e6   i,j<=1e9 所以需要离散化 不然内存必爆
const int maxn=1e6+5;
int t,n;
int father[maxn];
int book[maxn*3];
struct Node{
    int x,y,z;
}node[maxn];

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline void InIt(int nn){
    for(int i=1;i<=nn;i++) father[i]=i;
}

inline int find_father(int x){
    if(x==father[x]) return x;
    else return father[x]=find_father(father[x]);
}

bool cmp(Node a,Node b){
    return a.z>b.z;
}

int main(){
    t=read();
    while(t--){
        int tot=-1;
        memset(book,0,sizeof(book));
        memset(node,0,sizeof(node));
        memset(father,0,sizeof(father));
        int flga=1;
        n=read();
        for(int i=1;i<=n;i++){
            node[i].x=read();
            node[i].y=read();
            node[i].z=read();
            book[++tot]=node[i].x;
            book[++tot]=node[i].y;
        }
        sort(book,book+tot);     
        int nn=unique(book,book+tot)-book;
        for(int i=1;i<=n;i++){
            node[i].x=lower_bound(book,book+nn,node[i].x)-book;
            node[i].y=lower_bound(book,book+nn,node[i].y)-book;
        }
        InIt(nn);
        sort(node+1,node+n+1,cmp);
        for(int i=1;i<=n;i++){
            int fx=find_father(node[i].x);
            int fy=find_father(node[i].y);
            if(node[i].z){
                father[fx]=fy;
            }else if(fx==fy){
                printf("NO\n");
                flga=0;
                break;
            }
        }
        if(flga) printf("YES\n");
    }
    return 0;
}