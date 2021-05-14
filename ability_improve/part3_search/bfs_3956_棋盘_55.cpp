#include<bits/stdc++.h>
using namespace std;
const int maxn=1001,maxm=101;
int g[maxm][maxm],cost[maxm][maxm];
int m,n;
const int inf=0x3f3f3f3f;
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int vis[maxm][maxm];
struct Node{
    int x,y,c,f;
};
queue<Node>q;
inline void bfs(){
    //从起点(1,1)开始到终点(m,m)
    cost[1][1]=0;
    // vis[1][1]=1;
    Node node;  node.x=1; node.y=1; node.c=g[1][1]; node.f=0;    //flag==0代表没有变色
    q.push(node);
    
    while(!q.empty()){
        int xx=q.front().x,yy=q.front().y,cc=q.front().c,ff=q.front().f;
        if(xx==4&&yy==3) cout<<"!!!!"<<cc<<"  "<<ff<<" "<<cost[xx][yy]<<endl;
        q.pop();
        // vis[xx][yy]=1;
        for(int i=0;i<4;i++){
            int xxx=xx+dx[i],yyy=yy+dy[i];
            if(xxx<1||xxx>m||yyy<1||yyy>m||vis[xxx][yyy]) continue;
            int ccc=g[xxx][yyy];
            Node nn; nn.x=xxx; nn.y=yyy; nn.c=ccc; nn.f=0;
            if(ccc==cc){
                //如果两个颜色相同
                cost[xxx][yyy]=min(cost[xxx][yyy],cost[xx][yy]);
                // vis[xxx][yyy]=1;
            }else if((ccc==1&&cc==0)||(ccc==0&&cc==1)){
                //如果一个是黄色一个是红色 过去要花费一个金币
                //ccc==1&&cc==0 || ccc==0&&cc==1
                cost[xxx][yyy]=min(cost[xxx][yyy],cost[xx][yy]+1);
                // vis[xxx][yyy]=1;
            }else if(ccc==-1){
                //下一个方格为白色
                if(ff==1) continue; //如果之前的是变过色的 则这个无法再变色了
                else{
                    //如果之前的没变色 就使用魔法变成之前的颜色
                    nn.c=g[xx][yy];
                    nn.f=1;
                    cost[xxx][yyy]=min(cost[xxx][yyy],cost[xx][yy]+2);
                    // vis[xxx][yyy]=1;
                }
            }
            q.push(nn); 
            //一开始10'(因为忘记入队操作了) 加上入队操作 --> 50'
        }
        vis[xx][yy]=1;
        // if()
    }
}

int main(){
    m=read(); n=read();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++) g[i][j]=-1;
    }
    for(int i=1;i<=n;i++){
        int x,y;
        x=read(); y=read();
        g[x][y]=read();
    }
    memset(cost,0x3f,sizeof(cost));
    bfs();

    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) printf("%-4d",g[i][j]);
    //     cout<<endl;
    // }

    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) printf("%-12d",cost[i][j]);
    //     cout<<endl;
    // }

    if(cost[m][m]!=inf) printf("%d",cost[m][m]);
    else printf("-1");
    return 0;
}