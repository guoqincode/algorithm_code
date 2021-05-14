#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
int n,m;
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) father[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) Union(b,c);
        else if(a==2){
            if(findroot(b)==findroot(c)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}