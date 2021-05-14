//p1536 村村通
#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int father[maxn];
int n,m;

inline int findfather(int x){
    if(father[x]==x) return x;
    else return father[x]=findfather(father[x]);
}

inline void init_father(){
    for(int i=1;i<=n;i++) father[i]=i;
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        init_father();
        if(m==0){
            int zero;
            scanf("%d",&zero);
            printf("%d\n",n-1);
            continue;
        }
        int ans=n-1;
        init_father();
        int a,b;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            int fa=findfather(a),fb=findfather(b);
            if(fa!=fb){
                father[fb]=fa;
                ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

