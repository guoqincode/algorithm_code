//100'
#include<bits/stdc++.h>
using namespace std;
#define min(a,b) (((a)<(b))?(a):(b)) 
//洛谷 P1433 吃奶酪 状压DP
double a[20][20];//预处理，从第i块到第j块的距离，使用两点之间距离公式 
double x[20],y[20];//每块奶酪的横、纵坐标
double F[18][34000];//状压DP数组 在第i个点上，走过的二进制状态的十进制表达为j时，最短的距离 
int N; 
double distance(int v,int w)//计算第v个和第w个奶酪之间的距离 
{
	return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));//两点间距离公式 
}
int main()
{
	int i,j,k;
	double ans;
	memset(F,127,sizeof(F));//这样可以给浮点数赋值无穷大 
	ans=F[0][0];
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);//数据读入 
	}
	x[0]=0;y[0]=0;
	for(i=0;i<=N;i++)
	{
		for(j=i+1;j<=N;j++)
		{
			a[i][j]=distance(i,j);//初始化距离数组 
			a[j][i]=a[i][j];
		}
	} 
	for(i=1;i<=N;i++)//初始化 
	{
		F[i][(1<<(i-1))]=a[0][i];//在i点上且只有经过i点时距离是原点到i点的距离 
	}
	for(k=1;k<(1<<N);k++)//枚举所有二进制的状态 
	{
		for(i=1;i<=N;i++)
		{
			if((k&(1<<(i-1)))==0)
				continue;//i的位置没被走过，所以不需要再继续计算了 
			for(j=1;j<=N;j++)
			{
				if(i==j)
					continue;//同一个点不需要再计算 
				if((k&(1<<(j-1)))==0)
					continue;//j的位置没走过  
				F[i][k]=min(F[i][k],F[j][k-(1<<(i-1))]+a[i][j]);
			} 
		} 
	} 
    // for(int i=1;i<=N;i++) cout<<F[i][(1<<N)-1]<<endl;
	for(i=1;i<=N;i++)
	{
		ans=min(ans,F[i][(1<<N)-1]);
	}
	printf("%.2f\n",ans);
}