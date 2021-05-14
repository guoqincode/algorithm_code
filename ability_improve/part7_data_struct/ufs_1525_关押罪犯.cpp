#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxm=100010;
int father[maxn];
int enemy[maxn];    //存储敌人 实现敌人的敌人是朋友
int n,m;

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

struct Edge{
    int x,y,z;
}edge[maxn];

inline void Init(){
    for(int i=1;i<=n;i++) father[i]=i;
}

bool cmp(Edge a,Edge b){
    //将怨气值从大到小排序
    return a.z>b.z; 
}

int main(){
    n=read(); m=read();
    Init();
    for(int i=1;i<=m;i++){
        edge[i].x=read(); edge[i].y=read(); edge[i].z=read();
    }
    sort(edge+1,edge+m+1,cmp);

    for(int i=1;i<=m;i++){
        int a=edge[i].x,b=edge[i].y;
        if(findfather(a)==findfather(b)){
            printf("%d",edge[i].z);
            return 0;
        }else{
            if(!enemy[a]){
                //a目前没有敌人
                enemy[a]=b;
            }else{
                UnIoN(enemy[a],b);
            }
            if(!enemy[b]){
                enemy[b]=a;
            }else{
                UnIoN(enemy[b],a);
            }
        }
    }
    printf("0");
    return 0;
}