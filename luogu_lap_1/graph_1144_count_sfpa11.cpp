#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
inline int read()
{
	char ch=getchar(); 
	int x=0,f=1;
	while((ch>'9'||ch<'0')&&ch!='-')
		ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
    	x=x*10+ch-'0';
    	ch=getchar();
	}
	return x*f;
}
int mod=100003;
int n,m,x,y,tot=0;
const int N=1000005,M=4000005;
int head[N],to[M],nxt[M],d[N],ans[N];
bool p[N];
queue< int > q;
void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();y=read();
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		d[i]=1e9;p[i]=0;
	}
	d[1]=0;
	p[1]=1;
	ans[1]=1;
	q.push(1);
	while(q.size())
	{
		x=q.front();q.pop();
		p[x]=0;
		for(int i=head[x];i;i=nxt[i])
		{
			y=to[i];
			if(d[y]>d[x]+1)
			{
				d[y]=d[x]+1;
				ans[y]=ans[x];
				if(!p[y])
				{
					q.push(y);
					p[y]=1;
				}
			}
			else if(d[y]==d[x]+1)
			{
				ans[y]+=ans[x];
				ans[y]%=mod;
			}
		}
	}
    for(int i=1;i<=n;i++)
		printf("%d ",d[i]);
    cout<<endl;
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;	
} 