//p1233 木棍加工
//从dilworth定理中，我们可知，下降子序列的最小划分等于最长不下降子序列的长度
#include<bits/stdc++.h>
using namespace std;
const int maxn=5001;
struct Edge{
    int l,w;
}edge[maxn];
int n,f[maxn],ans=0;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}

bool cmp(Edge a,Edge b){
    if(a.l!=b.l) return a.l>b.l;
    else return a.w>b.w;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++) edge[i].l=read(),edge[i].w=read();
    sort(edge+1,edge+n+1,cmp);
    for (int i=1; i<=n;i++){
        if(edge[i].w>f[ans]) f[++ans]=edge[i].w;
        else{
            int l=1,r=ans;
            while(l<r){
                int mid=(l+r)>>1;
                if(f[mid]>=edge[i].w) r=mid;
                else l=mid+1;
            }
            f[l]=edge[i].w;
        }
    }
    printf("%d",ans);
    return 0;
    
}