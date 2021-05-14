#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1001;
queue<int>q;
int vis[maxn];
int temp,ans=0;
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>temp;
        if(vis[temp]) continue;
        ans++;
        if(q.size()<m){
            q.push(temp);
            vis[temp]=1;
        }else{
            int a=q.front();
            q.pop();
            vis[a]=0;
            q.push(temp);
            vis[temp]=1;
        }
    }
    cout<<ans;
    return 0;
}