#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
int n,m,p,a,b;
int father[maxn];
int findroot(int x){
    if(x==father[x]) return x;
    // else return findroot(father[x]);
    else return father[x]=findroot(father[x]);  //路径压缩
}

void Union(int a,int b){    //这样合并
    int fa=findroot(a);
    int fb=findroot(b);
    if(fa!=fb) father[fb]=fa;
}

int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        Union(a,b);
    }
    for(int i=1;i<=p;i++){
        cin>>a>>b;
        if(findroot(a)==findroot(b)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}