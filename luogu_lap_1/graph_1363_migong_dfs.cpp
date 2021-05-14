#include<bits/stdc++.h>
using namespace std;
const int maxn=1501;
char gra[maxn][maxn];
int vis[maxn][maxn][3];
int n,m;
int stx,sty;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int ans=0;
void dfs(int x,int y,int posx,int posy){
    if(vis[posx][posy][2]&&(vis[posx][posy][0]!=x||vis[posx][posy][1]!=y)){
        ans=1;
        return;
    }
    if(vis[posx][posy][2]&&vis[posx][posy][0]==x&&vis[posx][posy][1]==y) return;  //对于又转回来的情况
    vis[posx][posy][0]=x,vis[posx][posy][1]=y,vis[posx][posy][2]=1;
    for(int i=0;i<=3;i++){
        int tempx=(posx+dx[i]+n)%n;
        int tempy=(posy+dy[i]+m)%m;
        if(gra[tempx][tempy]=='.') dfs(x+dx[i],y+dy[i],tempx,tempy);
    }
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        memset(vis,0,sizeof(vis));
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>gra[i][j];
                if(gra[i][j]=='S'){
                    stx=i,sty=j;
                    gra[i][j]='.';  //把起点标记下来后 'S'-->'.'
                }
            }
        }
        dfs(stx,sty,stx,sty);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}