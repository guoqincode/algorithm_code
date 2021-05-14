#include<bits/stdc++.h>
using namespace std;
const int maxn=30001;
int father[maxn],dis[maxn],have[maxn];
int T,u,v;
char op;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline int findfather(int x){
    if(father[x]==x) return father[x];
    // else return father[x]=findfather(father[x]);
    int fx=findfather(father[x]);
    dis[x]+=dis[father[x]]; //通过回溯  更新距离祖先的距离
    return father[x]=fx;
}

// inline void UnIoN(int a,int b){
//     int fa=findfather(a);
//     int fb=findfather(b);
//     have[fb]+=have[fa]; have[fa]=0;
//     father[fa]=fb;
// }

inline void Init(){
    for(int i=1;i<=maxn;i++){
        father[i]=i;
        dis[i]=0;   //一开始 距离队头都是0
        have[i]=1;  //以i为队头的队列的飞船数量 初始时都是1
    }
}

int main(){
    Init();
    T=read();
    while(T--){
        // scanf("%c",&op);
        // u=read(); v=read();
        cin>>op>>u>>v;
        int fu=findfather(u),fv=findfather(v);
        if(op=='M'){
            //UnIoN
            dis[fu]+=have[fv];
            father[fu]=fv;
            have[fv]+=have[fu];
            have[fu]=0;
        }else if(op=='C'){
            if(fu!=fv) cout<<-1<<endl;
            else cout<<abs(dis[u]-dis[v])-1<<endl;
        }
    }
    return 0;
}