#include<bits/stdc++.h>
using namespace std;
const int maxn=401;
int g[maxn][maxn],vis[maxn][maxn];
int n,m,stx,sty;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}
struct Node{
    int x;
    int y;
};
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
queue<Node>q;
int step=0;
inline void bfs(int stx,int sty){
    vis[stx][sty]=1;
    Node node;
    node.x=stx,node.y=sty;
    q.push(node);
    while(!q.empty()){
        int ss=q.size();
        step++;
        for(int i=1;i<=ss;i++){
            Node nn=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int tempx=nn.x+dx[i],tempy=nn.y+dy[i];
                if(tempx<1||tempx>n||tempy<1||tempy>m||vis[tempx][tempy]) continue;
                g[tempx][tempy]=step;
                Node nnn; nnn.x=tempx; nnn.y=tempy;
                q.push(nnn);
                vis[tempx][tempy]=1;
            }
        }
    }
}

int main(){
    n=read(); m=read(); stx=read(); sty=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) g[i][j]=-1;
    }
    g[stx][sty]=0;
    bfs(stx,sty);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // if(j==1){
            //     printf("%d ",g[i][j]);
            //     continue;
            // }
            printf("%-4d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;
}