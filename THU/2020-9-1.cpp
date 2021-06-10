#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int w_a[maxn],w_b[maxn];
int son_a[maxn],son_b[maxn];    //记录儿子个数
int n,m,sum;
int main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w_a[i];
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        son_a[u]++;
    }

    cin>>m;
    for(int i=1;i<=m;i++) cin>>w_b[i];
    for(int i=1;i<=m-1;i++){
        int u,v;
        cin>>u>>v;
        son_b[u]++;
    }

    cin>>sum;
    int flag=0;

    for(int i=1;i<=n;i++){
        if(son_a[i]!=2) continue;
        for(int j=1;j<=m;j++){
            if(son_b[j]!=2) continue;
            if(w_a[i]+w_b[j]==sum){
                cout<<i<<" "<<j<<endl;
                flag=1;
            }
        }
    }
    if(!flag) cout<<-1;
    return 0;
}