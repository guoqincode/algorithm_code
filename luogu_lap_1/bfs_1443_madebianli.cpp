//马的遍历，求出(x,y)到n*m矩阵内所有点的距离
//马行走的方式和象棋中马行走的方式相同
//典型的bfs
#include<bits/stdc++.h>
using namespace std;
int dx[16]={2,-2,2,-2,1,1,-1,-1};
int dy[16]={1,1,-1,-1,2,-2,2,-2};
typedef struct{
    int x,y;
}point;
int test(int newx,int newy,int n,int m){
    if((newx>=0)&&(newx<n)&&(newy>=0)&&(newy<m)) return 1;
    else return 0;
}
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector< vector<int> >get(n,vector<int>(m,-1));
    vector< vector<int> >dis(n,vector<int>(m,-1));
    queue< point >q;
    point start;
    start.x=x-1;
    start.y=y-1;
    dis[start.x][start.y]=0;
    q.push(start);
    get[start.x][start.y]=1;
    int step=1;
    while(!q.empty()){
        int nn=q.size();
        while(nn--){
            point temp=q.front();
            q.pop();
            //cout<<temp.x<<temp.y;
            for(int i=0;i<8;i++){
                int newx=temp.x+dx[i];
                int newy=temp.y+dy[i];
                //cout<<newx<<newy<<endl;
                //cout<<test(newx,newy,n,m)<<endl;
                //cout<<(get[newx][newy]==-1)<<endl;
                if(test(newx,newy,n,m)&&get[newx][newy]==-1){
                    //找到了下一步可达的位置
                    //cout<<"hello!";//
                    get[newx][newy]=1;
                    dis[newx][newy]=step;
                    point curtemp;
                    curtemp.x=newx;
                    curtemp.y=newy;
                    q.push(curtemp);
                    //cout<<"hello!";
                }
            }
        }
        step++;
    }
    for(int i=0;i<n;i++){
        //printf("%d",dis[i][0]);
        for(int j=0;j<m;j++){
            printf("%-5d",dis[i][j]);
        }
        cout<<endl;
    }
    return 0;
}