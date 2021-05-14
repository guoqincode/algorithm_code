//满分代码 以地点+时间为状态
#include<bits/stdc++.h>
using namespace std;
int n,m,t,stx,sty,edx,edy;
const int maxn=101,maxt=16;
int f[maxn][maxn][maxt];  //前两维是地点 最后一个维度是时间/步数
int g[maxn][maxn];
// int ans=0;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

struct node{
    int x;
    int y;
    int step;
};
queue<node>q;
inline void bfs(){
    f[stx][sty][0]=1;
    q.push(node{stx,sty,0});
    while(q.size()){
        auto nn=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            node nnn;
            nnn.x=nn.x+dx[i],nnn.y=nn.y+dy[i],nnn.step=nn.step+1;
            if(f[nnn.x][nnn.y][nnn.step]){
                f[nnn.x][nnn.y][nnn.step]+=f[nn.x][nn.y][nn.step];
                continue;   //当前状态曾被拓展
            }
            if(nnn.x<1||nnn.x>n||nnn.y<1||nnn.y>m||g[nnn.x][nnn.y]==1||nnn.step>t) continue;
            f[nnn.x][nnn.y][nnn.step]+=f[nn.x][nn.y][nn.step];
            q.push(nnn);
        }
    }
}

int main(){
    n=read(); m=read(); t=read();
    // cout<<n<<m<<t<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char temp;
            // scanf("%c",&temp);
            cin>>temp;
            if(temp=='*') g[i][j]=1;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         // char temp;
    //         // scanf("%c",&temp);
    //         // if(temp=='*') g[i][j]=1;
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    stx=read(); sty=read(); edx=read(); edy=read();

    bfs();

    printf("%d",f[edx][edy][t]);
    return 0;
}