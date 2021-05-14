#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,m;
int st[maxn],vis[maxn],topo[maxn][maxn],chu[maxn];
int top,bo[maxn],tt[maxn];
int main(){
    cin>>n>>m;
    for(int ii=1;ii<=m;ii++){
        memset(vis,0,sizeof(vis));
        int s;
        cin>>s;
        for(int k=1;k<=s;k++){
            cin>>st[k]; //st[i]为停靠的站点
            vis[st[k]]=1;
        }
        for(int i=st[1];i<=st[s];i++){
            if(!vis[i]){
                //i点未被访问过
                for(int j=1;j<=s;j++){
                    if(!topo[i][st[j]]){
                        topo[i][st[j]]=1;
                        chu[st[j]]++;
                    }
                }
            }
        }
    }
    memset(bo,0,sizeof(bo));
    int ans=0;
    do{
        top=0;
        for(int i=1;i<=n;i++){
            if(chu[i]==0&&!bo[i]){
                tt[++top]=i,bo[i]=1;
            }
        }
        for(int i=1;i<=top;i++){
            for(int j=1;j<=n;j++){
                if(topo[tt[i]][j]){
                    topo[tt[i]][j]=0;
                    chu[j]--;
                }
            }
        }
        ans++;  //去掉了一层
    }while(top);
    cout<<ans-1;
    return 0;
}