#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
struct node{
    int x,y;
}Node;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int n,m;    //矩阵大小为n*m
int matrix[maxn][maxn];     //0 1 矩阵
bool inq[maxn][maxn]={false};   //记录(x,y)是否入过队
bool judge(int newx,int newy){  //判断(newx,newy)是否需要访问
    if(newx>=n||newy>=m||newx<0||newy<0) return false;
    if(matrix[newx][newy]==0||inq[newx][newy]==true) return false;
    return true;
}
void bfs(int x,int y){
    queue<node>q;
    Node.x=x,Node.y=y;
    q.push(Node);
    inq[x][y]=true;
    while(!q.empty()){
        node top=q.front();
        q.pop();
        for(int i=0;i<4;i++){       //->size == 4
            int newx=top.x+dx[i];
            int newy=top.y+dy[i];
            if(judge(newx,newy)){
                Node.x=newx,Node.y=newy;
                q.push(Node);
                inq[newx][newy]=true;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1&&inq[i][j]==false){
                bfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}