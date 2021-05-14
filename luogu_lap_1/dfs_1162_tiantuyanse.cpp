#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=32;
int gra[maxn][maxn],is_one[maxn][maxn]={0};

void dfs(int i,int j){
    if(i<1||i>n||j<1|j>n||gra[i][j]==1) return;
    gra[i][j]=1;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>gra[i][j];
            if(gra[i][j]==1) is_one[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(gra[i][1]!=1) dfs(i,1);
        if(gra[i][n]!=1) dfs(i,n);
    }
    for(int j=1;j<=n;j++){
        if(gra[1][j]!=1) dfs(1,j);
        if(gra[n][j]!=1) dfs(n,j);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(is_one[i][j]==1) cout<<"1 ";
            else if(gra[i][j]==0) cout<<"2 ";
            else cout<<"0 "; 
        }
        cout<<endl;
    }
    return 0;
}
