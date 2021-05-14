#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,temptx,tempty,count_of_lines;
int area[7][7]={0};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int vis[7][7]={false};
void dfs(int cur_x,int cur_y){
    if(cur_x==fx&&cur_y==fy){
        count_of_lines++;
        return;
    }
    for(int i=0;i<4;i++){
        int newx=cur_x+dx[i],newy=cur_y+dy[i];
        if(vis[newx][newy]==false&&area[newx][newy]==0&&newx>=1&&newx<=n&&newy>=1&&newy<=m){
            vis[newx][newy]=true;
            dfs(newx,newy);
            vis[newx][newy]=false;
        }
    }
}
int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=1;i<=t;i++){
        cin>>temptx>>tempty;
        area[temptx][tempty]=1;
    }
    vis[sx][sy]=true;
    dfs(sx,sy);
    cout<<count_of_lines;
    return 0;
}