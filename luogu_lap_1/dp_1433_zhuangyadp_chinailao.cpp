//p1433 吃奶酪 状压dp
//90'
#include<bits/stdc++.h>
using namespace std;
const int maxn=16;
double x[maxn],y[maxn],dis[maxn][maxn];
int n;
double dp[maxn+2][(1<<maxn)+10];
inline double return_dis(int i,int j){
    return (double)sqrt(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}

inline int read(){
    int x=0,f=1; char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch-'0'); ch=getchar();}
    return x*f;
}

int main(){
    // n=read();
    scanf("%d",&n);
    x[0]=y[0]=0;
    memset(dp,127,sizeof(dp));  //给浮点数赋值无穷大 
    double ans=dp[0][0];
    for(int i=1;i<=n;i++){
        // scanf("%lf &lf",&x[i],&y[i]);
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<=n;i++){
        // dis[i][i]=0;
        for(int j=i+1;j<=n;j++){
            dis[i][j]=return_dis(i,j);
            dis[j][i]=dis[i][j];
        }
    }
    for(int i=1;i<=n;i++) dp[i][1<<(i-1)]=dis[0][i];//初始化每个点到原点的距离
    for(int k=1;k<(1<<n);k++){
        //枚举所有的二进制状态
        for(int i=1;i<=n;i++){
            if(k&&(1<<(i-1))==0) continue;  //i的位置没被走过，所以不需要重新计算了
            for(int j=1;j<=n;j++){
                if(i==j) continue;  //同一个点不需要再计算
                if(k&&(1<<(j-1))==0) continue;
                //第二个是走过j没走过i的最短距离加上ij之间的距离
                dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dp[i][(1<<n)-1]<<endl;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf",ans);
    return 0; 
}
