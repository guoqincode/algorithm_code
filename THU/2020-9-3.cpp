#include<bits/stdc++.h>
using namespace std;
//遇到这种题目 在有限的时间内 我只能骗分  -.-!
const int maxn = 201;
int n,m,g[maxn][maxn],cost_j,cost_i;
int x,y,fadian[5],factory[5];
//子任务1 x=1 y=1
//子任务2 y=1
//子任务3 x=1 y=2
//子任务4 x=1
const int inf = 0x3f3f3f3f;
int d[40010],vis[40010];

void slove_x_y(int traget,int &x,int &y){
    //利用target返回 x 和 y
    if(traget%m==0){
        y=m;
        x=traget/m;
    }else{
        y=traget%m;
        x=traget/m+1;
    }
    return;
}

struct Edge{
    int from,to,next,dis;
}edge[160010];

int head[40010];    //每个节点的编号为 (i-1)*m+j
int tot = 0;
inline void addedge(int from,int to,int dis){
    tot++;
    edge[tot].from = from;
    edge[tot].to = to;
    edge[tot].next = head[from];
    edge[tot].dis = dis;
    head[from] = tot;
}

inline int spfa(int from,int to){
    fill(d,d+n*m+10,inf);
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(from);
    d[from] = 0;
    vis[from] = 1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i=head[u];i;i=edge[i].next){
            int v = edge[i].to;
            
            if(d[v]>d[u]+edge[i].dis){
                d[v]=d[u]+edge[i].dis;
                if(vis[v]==0){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    return d[to];
}

int main(){
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
            if(g[i][j]>0){
                //记录工厂的个数和位置
                x++;
                fadian[x] = (i-1)*m+j;
            }
            else if(g[i][j]==-1){
                y++;
                factory[y] = (i-1)*m+j;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            //(i,j) - (i,j+1)
            cin>>cost_i;
            addedge((i-1)*m+j,(i-1)*m+j+1,cost_i);
            addedge((i-1)*m+j+1,(i-1)*m+j,cost_i);
        }
    }

    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            // (i,j) - (i+1,j)
            cin>>cost_j;
            addedge((i-1)*m+j,i*m+j,cost_j);
            addedge(i*m+j,(i-1)*m+j,cost_j);
        }
    }

    // cout<<"here"<<endl;

    if(x==1){
        //进入子任务 1，3，4  57'
        if(y==1){
            //进入子任务1     13'
            //一个发电站和一个工厂 求单个发电站到单个工厂的最短距离
            int ans = spfa(fadian[1],factory[1]);

            int cur_x,cur_y;
            slove_x_y(fadian[1],cur_x,cur_y);
            ans+=g[cur_x][cur_y];
            cout<<ans<<endl;

            return 0;
        }else if(y==2){
            //进入子任务3 y=2 21'  两种情况-->考虑错了orz
            // int ans_1 = spfa(fadian[1],factory[1]);
            // int ans_2 = dijk
        }
        
    }

    if(y==1){
        //进入子任务2   17'
        //多个发电站 一个工厂
        int ans = inf;
        for(int i=1;i<=x;i++){
            int tempans = spfa(fadian[i],factory[1]);
            int cur_x,cur_y;
            slove_x_y(fadian[i],cur_x,cur_y);
            tempans+=g[cur_x][cur_y];
            ans = min(ans,tempans);
        }
        cout<<ans;
        return 0;
    }

    else{
        //子任务5 26'
    }
}
