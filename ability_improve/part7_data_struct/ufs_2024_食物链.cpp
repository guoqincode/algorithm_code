#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+3;
const int maxnn=3*maxn;
int father[maxnn];
int n,k;
int ans=0;

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

inline int findfather(int x){
    if(x==father[x]) return x;
    else return father[x]=findfather(father[x]);
}

inline void UnIoN(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    father[fa]=fb;
}

inline void init(){
    for(int i=1;i<=3*n;i++) father[i]=i;    //x 为本身 x+n为猎物 x+2n为天敌
}


int main(){
    n=read(); k=read();
    init();
    int op,x,y;
    while(k--){
        op=read(); x=read(); y=read();
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(op==1){
            if(findfather(x+n)==findfather(y)||findfather(x+2*n)==findfather(y)){
                ans++;
                continue;
            }
            UnIoN(x,y); UnIoN(x+n,y+n); UnIoN(x+2*n,y+2*n);
        }else if(op==2){
            if(findfather(x)==findfather(y)||findfather(x+2*n)==findfather(y)){
                ans++;
                continue;
            }
            UnIoN(x,y+2*n); UnIoN(x+n,y); UnIoN(x+2*n,y+n);
        }
    }
    cout<<ans;
    return 0;
}