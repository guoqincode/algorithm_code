#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int curfloor;
    int step;
}ceng;
int n,a,b,lift[201],vis[201]={0};
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>lift[i];
    queue<ceng>q;
    ceng f1,f2;
    f1.curfloor=a;
    f1.step=0;
    vis[f1.curfloor]=1;
    q.push(f1);
    while(!q.empty()){
        f2=q.front();
        q.pop();
        if(f2.curfloor==b) break;
        int i=f2.curfloor+lift[f2.curfloor];
        if(i<=n&&!vis[i]){
            f1.curfloor=i;
            f1.step=f2.step+1;
            q.push(f1);
            vis[i]=1;
        }
        i=f2.curfloor-lift[f2.curfloor];
        if(i>=1&&!vis[i]){
            f1.curfloor=i;
            f1.step=f2.step+1;
            q.push(f1);
            vis[i]=true;
        }
    }
    if(f2.curfloor==b) cout<<f2.step;
    else cout<<-1;
    return 0;
}