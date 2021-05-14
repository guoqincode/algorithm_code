//dfs
#include<cstdio>
#include<math.h>
#define abs(a) ((a)>0? (a):(-(a)))
#define min(a,b)    ( (a) < (b) ? (a) : (b) )
#define max(a,b)    ( (a) > (b) ? (a) : (b) )
#define M_PI		3.14159265358979323846
int n;
double le,ri,down,up,tx,ty;
double x[7],y[7],ans=0,sum=0,d[7][7],r[7];
int vis[7];
inline double caldis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

inline void dfs(int xx,double sum){
    if(xx==n+1){
        ans=max(ans,sum);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //如果i还没有被选取
            // double ss= x[i] ;
            double a=min(y[i]-down,up-y[i]);
            double b=min(x[i] - le , ri - x[i]);
            r[i]=min(a,b);  //第一次确定半径的值
            for(int j=1;j<=n;j++){
                if(vis[j]) r[i]=min(r[i],d[i][j]-r[j]);
            }
            vis[i]=1;
            if(r[i]<0) r[i]=0;
            dfs(xx+1,sum+r[i]*r[i]*M_PI);
            vis[i]=0;   //回溯!!!
        }
    }
}

int main(){
    scanf("%d",&n);
    scanf("%lf%lf",&tx,&ty);//先读入一个顶点
	le=ri=tx;up=down=ty;//均赋值
	scanf("%lf%lf",&tx,&ty);//再读入另一个顶点
	le=min(le,tx),ri=max(ri,tx);
	down=min(down,ty),up=max(up,ty);
    for(int i=1;i<=n;i++) scanf("%lf %lf",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            d[i][j]=d[j][i]=caldis(i,j);
        }
    }
    dfs(1,0.0);
    printf("%.0lf",(up-down)*(ri-le)-ans);
    return 0;
}