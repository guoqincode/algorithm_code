#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans=INT_MAX,lift[205];
bool vis[205]={false};
void dfs(int now,int sum){
    //now->dangqian sum->andecishu
    if(now==b) ans=min(ans,sum);
    else if(sum<=ans){
        //jianzhi->if sum>ans ans不可能是最终答案
        vis[now]=true;
        if(now+lift[now]<=n&&!vis[now+lift[now]]) dfs(now+lift[now],sum+1);
        if(now-lift[now]<=n&&!vis[now-lift[now]]) dfs(now-lift[now],sum+1);
        vis[now]=false; //huisu
    }
}
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>lift[i];
    vis[a]=true;
    dfs(a,0);
    if(ans!=INT_MAX) cout<<ans;
    else cout<<"-1";
    return 0;
}