#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[105][105],val[105][105];
struct node{
    int x,y,c,v;
};
queue<node>q;
int main() {
    int m,n,di[4][2]={0,1,1,0,0,-1,-1,0},ans=0x3f3f3f3f;
    memset(map,-1,sizeof(map));
    memset(val,0x3f,sizeof(val));
    cin>>m>>n;
    for(int i=0;i<n;i++){
        int x,y,c;
        cin>>x>>y>>c;
        map[x][y]=c;
    }
    q.push((node){1,1,map[1][1],0});
    val[1][1]=0;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y,c=q.front().c,v=q.front().v;
        if(v>ans){
            q.pop();
            continue;
        }
        if(x==m&&y==m){
            ans=min(ans,v);
            q.pop();
            continue;
        }
        for(int k=0;k<4;k++){
            int dx=x+di[k][0],dy=y+di[k][1];
            if(dx>0&&dy>0&&dx<=m&&dy<=m){
                int bc=map[x][y],dc=map[dx][dy],mv=val[dx][dy],dv;
                if(dc>=0&&bc>=0){
                    dv=v+(dc==bc?0:1);
                    if(mv>dv){
                        q.push((node){dx,dy,dc,dv});
                        val[dx][dy]=dv;
                    }
                }else if(dc<0&&bc>=0){
                    if(mv>v+2){
                        q.push((node){dx,dy,bc,v+2});
                        val[dx][dy]=v+2;
                    }
                }else if(dc>=0&&bc<0){
                    dv=v+(c==dc?0:1);
                    if(mv>dv){
                        q.push((node){dx,dy,dc,dv});
                        val[dx][dy]=dv;
                    }
                }
            }
        }
        q.pop();
    }
    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=m;j++) printf("%-12d",val[i][j]);
    //     printf("\n");
    // }
    if(ans==0x3f3f3f3f){
        cout<<"-1"<<endl;
    }else {
        cout<<ans<<endl;
    }
    return 0;
}