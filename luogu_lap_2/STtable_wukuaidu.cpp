//ST表模板 RMQ问题
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,m,a,b;
int MAX[maxn][21];  //MAX[i][j]代表从a[i]开始的2^j个数中最大的值 即max(a[i]...a[i+2^j-1])
// inline int read(){
//     //快读    模板 记住
//     int x=0,f=1;
//     char ch=getchar();
//     while(!isdigit(ch)){
//         if(ch=='-') f=-1;
//         ch=getchar();
//     }
//     while(isdigit(ch)){
//         x=x*10+(ch-'0');
//         ch=getchar();
//     }
//     return x*f;
// }




inline int query(int left,int right){
    int k=log2(right-left+1);   //k=log2(len)
    return max(MAX[left][k],MAX[right-(1<<k)+1][k]);
}

int main(){
    // n=read(); m=read();
    scanf("%d%d",&n,&m);
    // for(int i=1;i<=n;i++) MAX[i][0]=read();
    for(int i=1;i<=n;i++) scanf("%d",&MAX[i][0]);
    for(int j=1;j<=21;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            //i+2^j-1<=n
            MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]);  //a[i]..a[i+2^(j-1)-1]  和 a[i+2^(j-1)]..a[i+2^j-1]最大值
        }
    }
    for(int i=1;i<=m;i++){
        // a=read(); b=read();
        scanf("%d%d",&a,&b);
        printf("%d\n",query(a,b));
    }
    return 0;
}