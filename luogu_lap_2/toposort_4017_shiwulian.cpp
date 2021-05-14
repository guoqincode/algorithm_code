#include<bits/stdc++.h>
using namespace std;
const int mod=80112002;
const int maxn=5001;
int n,m;
int chu[maxn],ru[maxn]; //出度和入度
int eat[maxn][maxn];    //eat[i][j]=1代表j可以吃掉i
int f[maxn];    //f[i]代表到达i点的食物链的个数
queue<int>q;
int main(){
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        chu[a]++;
        ru[b]++;
        eat[a][b]=1;
    }
    for(int i=1;i<=n;i++){
        if(ru[i]==0){
            q.push(i);
            f[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(eat[x][i]){
                //i可以吃掉x
                f[i]+=f[x];
                f[i]%=mod;
                ru[i]--;
                if(ru[i]==0){
                    if(chu[i]==0){
                        ans+=f[i];
                        ans%=mod;
                        continue;
                    }
                    q.push(i);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}