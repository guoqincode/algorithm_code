#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int stx,sty,edx,edy;
const int maxn=101;
int g[maxn][maxn],vis[maxn][maxn];
int ans=0;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
struct node{
    int x;
    int y;
    int step;
};
queue<node>q;
inline void bfs(){
    node n1; n1.x=stx,n1.y=sty,n1.step=0;
    q.push(n1);
    int curstep=0;
    // vis[stx][sty]=1;//在这里设置已经访问过吗？
    while(!q.empty()){
        //在这里用队列是否为空来跳出 但是最好的跳出方式是当前队列的步数为t时
        //此时再走的话肯定要超时
        int tempsize=q.size();  //q的大小会发生变化
        for(int k=0;k<tempsize;k++){
            node nn=q.front(); q.pop();
            for(int kk=0;kk<4;kk++){
                int tx=nn.x+dx[kk],ty=nn.y+dy[kk];
                if(tx==edx&&ty==edy){
                    ans++;
                    continue;
                }
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&g[tx][ty]==0&&vis[tx][ty]==0){
                    node nnn; nnn.x=tx,nnn.y=ty,nnn.step=nn.step+1;
                    q.push(nnn);
                    curstep=max(curstep,nnn.step);
                }
            }
            vis[nn.x][nn.y]=1;
        }
        if(curstep>=t) break;      //在这里做一个剪枝 在这里已经走到第t步了
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&t);
    char temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%c",&temp);
            if(temp=='*') g[i][j]=1;
            // else g[i][j]=1;
        }
    }
    scanf("%d%d%d%d",&stx,&sty,&edx,&edy);
    bfs();
    printf("%d",ans);
    return 0;
}