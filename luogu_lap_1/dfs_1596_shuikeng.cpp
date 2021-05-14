#include<bits/stdc++.h>
using namespace std;
int n,m,count_=0;
char pig[101][101];
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

int testedge(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<m) return 1;
    else return 0;
}
void dfs(int i,int j){
    pig[i][j]='.';
    for(int k=0;k<8;k++){
        int tempx=i+dx[k],tempy=j+dy[k];
        if(pig[tempx][tempy]=='W'&&testedge(tempx,tempy)){
           dfs(tempx,tempy); 
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>pig[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pig[i][j]=='W'){
                count_++;
                dfs(i,j);
            }
        }        
    }
    cout<<count_;
    return 0;
}