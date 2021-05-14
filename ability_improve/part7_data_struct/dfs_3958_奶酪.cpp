//dfs 60'  
//还可以用bfs  ufs做 
//ufs做法是 相交或相切的在一个并查集里 判断改并查集中是否既有起点也有终点
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n;
double h,r;
const int maxn=1e3+10;
struct RoUnD{
    int xx;
    int yy;
    int zz;
}Round[maxn];
int isend[maxn];
int vis[maxn];
// double dis[maxn][maxn];
inline ll read(){
    ll x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline double return_dis(int i,int j){
    return (double)sqrt(
                        (Round[i].xx-Round[j].xx)*(Round[i].xx-Round[j].xx)
                        +(Round[i].yy-Round[j].yy)*(Round[i].yy-Round[j].yy)
                        +(Round[i].zz-Round[j].zz)*(Round[i].zz-Round[j].zz)
                        );
}

bool cmp(RoUnD a,RoUnD b){
    return a.zz<b.zz;
}

// inline bool dfs(int x,int fa){
//     if(isend[x]) return true;
//     for(int i=1;i<=n;i++){
//         if(i==x) continue;
//         if(i==fa) continue;
//         if(dis[x][i]<=2*r){
//             //相交或者相切
//             if(dfs(i,x)) return true;
//         }
//     }
//     return false;
// }

inline bool dfs(int x){
    if(Round[x].zz+r>=h) return true;
    vis[x]=1;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(return_dis(i,x)<=2*r){
            //相交或者相切
            if(dfs(i)) return true;
        }
    }
    vis[x]=0;
    return false;
}

int main(){
    T=read();
    while(T--){
        n=read(); scanf("%lf",&h); scanf("%lf",&r);
        memset(isend,0,sizeof(isend));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            Round[i].xx=read(); Round[i].yy=read(); Round[i].zz=read();
        }

        sort(Round+1,Round+n+1,cmp);

        // for(int i=1;i<=n;i++) if(Round[i].zz+r>=h) isend[i]=1;
        // for(int i=1;i<=n;i++){
        //     dis[i][i]=0;
        //     for(int j=i+1;j<=n;j++) dis[i][j]=dis[j][i]=return_dis(i,j);
        // }

        int flag=0;

        for(int i=1;i<=n;i++){
            if(Round[i].zz<=r){
                if(dfs(i)){
                    cout<<"Yes"<<endl;
                    flag=1;
                    break;
                }
            }else break;    //加速一下
        }
        if(flag==0) cout<<"No"<<endl;
    }
    return 0;
}